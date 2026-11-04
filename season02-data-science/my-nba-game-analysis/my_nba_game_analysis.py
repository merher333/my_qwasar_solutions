import re
import sys
from collections import defaultdict

def init_stats():
    return {
        "FG": 0, "FGA": 0,
        "3P": 0, "3PA": 0,
        "FT": 0, "FTA": 0,
        "ORB": 0, "DRB": 0,
        "TRB": 0, "AST": 0,
        "STL": 0, "BLK": 0,
        "TOV": 0, "PF": 0,
        "PTS": 0
    }

def parse_play_line(line):
    """Split raw line into its components."""
    period, rem, off, away, home, away_sc, home_sc, desc = line.strip().split("|", 7)
    return {
        "period": int(period),
        "remaining_sec": float(rem),
        "offense_team": off,
        "away": away,
        "home": home,
        "away_score": int(away_sc),
        "home_score": int(home_sc),
        "desc": desc
    }

def update_stats_for_play(teams, play):
    """Given teams dict and one play, identify actor(s) and update stats."""
    side = "home" if play["offense_team"] == play["home"] else "away"
    desc = play["desc"]
    # find the primary actor
    names = re.findall(r"([A-Z]\.\s[\w’]+)", desc)
    if not names:
        return
    actor = names[0]
    stats = teams[side]["players"][actor]

    # scoring
    if "makes 3-pt" in desc:
        stats["3PA"] += 1; stats["3P"] += 1
        stats["FGA"] += 1; stats["FG"] += 1; stats["PTS"] += 3
    elif "misses 3-pt" in desc:
        stats["3PA"] += 1; stats["FGA"] += 1
    elif "makes 2-pt" in desc:
        stats["FGA"] += 1; stats["FG"] += 1; stats["PTS"] += 2
    elif "misses 2-pt" in desc:
        stats["FGA"] += 1
    elif "makes free throw" in desc:
        stats["FTA"] += 1; stats["FT"] += 1; stats["PTS"] += 1
    elif "misses free throw" in desc:
        stats["FTA"] += 1

    # rebounds
    if desc.startswith("Offensive rebound"):
        stats["ORB"] += 1
    elif desc.startswith("Defensive rebound"):
        stats["DRB"] += 1

    # assists
    m = re.search(r"assist by ([A-Z]\.\s[\w’]+)", desc)
    if m:
        teams[side]["players"][m.group(1)]["AST"] += 1

    # steals
    m = re.search(r"steal by ([A-Z]\.\s[\w’]+)", desc)
    if m:
        teams[side]["players"][m.group(1)]["STL"] += 1

    # blocks
    m = re.search(r"block by ([A-Z]\.\s[\w’]+)", desc)
    if m:
        teams[side]["players"][m.group(1)]["BLK"] += 1

    # turnovers
    if desc.startswith("Turnover by"):
        stats["TOV"] += 1

    # personal fouls
    m = re.search(r"foul by ([A-Z]\.\s[\w’]+)", desc)
    if m:
        teams[side]["players"][m.group(1)]["PF"] += 1

def analyse_nba_game(play_by_play_moves):
    """Main analyzer: returns the nested dict of home/away with players_data."""
    teams = {
        "home": {"name": None, "players": defaultdict(init_stats)},
        "away": {"name": None, "players": defaultdict(init_stats)},
    }

    for raw in play_by_play_moves:
        play = parse_play_line(raw)
        # record team names from the first play
        if teams["home"]["name"] is None:
            teams["home"]["name"] = play["home"]
            teams["away"]["name"] = play["away"]
        update_stats_for_play(teams, play)

    # finalize total rebounds and build output structure
    for side in ("home", "away"):
        for p, s in teams[side]["players"].items():
            s["TRB"] = s["ORB"] + s["DRB"]

    return {
        "home_team": {
            "name": teams["home"]["name"],
            "players_data": [
                {"player_name": p, **s}
                for p, s in teams["home"]["players"].items()
            ]
        },
        "away_team": {
            "name": teams["away"]["name"],
            "players_data": [
                {"player_name": p, **s}
                for p, s in teams["away"]["players"].items()
            ]
        }
    }

def print_nba_game_stats(team_dict):
    headers = [
        "Players","FG","FGA","FG%","3P","3PA","3P%","FT","FTA","FT%","ORB","DRB","TRB",
        "AST","STL","BLK","TOV","PF","PTS"
    ]
    print("\t".join(headers))

    def pct(made, att):
        if not att:
            return ""
        r = made/att
        s = f"{r:.3f}"
        return s if r == 1 else s.lstrip("0")

    def fmt_row(name, stats):
        row = [name,
               str(stats["FG"]), str(stats["FGA"]), pct(stats["FG"], stats["FGA"]),
               str(stats["3P"]), str(stats["3PA"]), pct(stats["3P"], stats["3PA"]),
               str(stats["FT"]), str(stats["FTA"]), pct(stats["FT"], stats["FTA"])]
        for k in ["ORB","DRB","TRB","AST","STL","BLK","TOV","PF","PTS"]:
            row.append(str(stats[k]))
        print("\t".join(row))

    for side in ("home_team","away_team"):
        team = team_dict[side]
        print(f"\n=== {team['name']} ===")
        total = {k: 0 for k in ["FG","FGA","3P","3PA","FT","FTA","ORB","DRB","AST","STL","BLK","TOV","PF","PTS"]}

        for p in team["players_data"]:
            fmt_row(p["player_name"], p)
            for k in total:
                total[k] += p[k]

        total["TRB"] = total["ORB"] + total["DRB"]
        fmt_row("Team Totals", total)

def load_play_by_play(filepath):
    plays = []
    with open(filepath, encoding="utf-8") as f:
        for lineno, raw in enumerate(f, start=1):
            line = raw.strip()
            if not line:
                continue
            if line.count("|") < 7:
                # warn you so you can correct the file if needed
                print(f"Skipping invalid line {lineno!s}: {line!r}")
                continue
            plays.append(line)
    return plays

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 my_nba_game_analysis.py plays.txt")
        sys.exit(1)

    plays = load_play_by_play(sys.argv[1])
    summary = analyse_nba_game(plays)
    print_nba_game_stats(summary)
