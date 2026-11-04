# Welcome to My NBA Game Analysis
***

## Task
Parse a stream of NBA play-by-play lines and produce a box-score summary for each team.

## Description
- **analyse_nba_game(play_by_play_moves)** reads each “PERIOD|…|DESCRIPTION” line, updates per-player stats (FG, FGA, 3P, 3PA, FT, FTA, ORB, DRB, AST, STL, BLK, TOV, PF, PTS) and returns a nested dict for home and away teams.  
- **print_nba_game_stats(team_dict)** takes that dict and prints a tab-separated box-score with player lines and team totals.

## Installation
No external dependencies beyond the Python standard library.
create a venv
python3 -m venv venv
source venv/bin/activate
install if you ever add requirements
pip install -r requirements.txt
## Usage
Run: python3 my_nba_game_analysis.py

```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
