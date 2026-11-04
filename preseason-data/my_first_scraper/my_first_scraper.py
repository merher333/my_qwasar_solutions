# I already see too much nonsense code with Selenium that we don't even need. Let's purge it.
# We only need requests and BeautifulSoup to get the job done.

import requests  # This is like our internet robot friend that can fetch pages for us
from bs4 import BeautifulSoup  # This is our HTML translator buddy that helps us find hidden treasures in the markup

def request_github_trending(url):
    # I am making a GET request. Fancy talk for: "Hey server, give me the page."
    response = requests.get(url)
    if response.status_code != 200:
        # If the server doesn’t give us a smiley face (status 200), we bail out dramatically.
        raise Exception(f"Request failed with status code: {response.status_code}")
    # If the code survives till here, it means we got HTML, so let's hand it over.
    return response

def extract(page):
    # Now let's parse the HTML with BeautifulSoup—our HTML language expert.
    soup = BeautifulSoup(page.text, 'html.parser')
    # We are going to find all the articles with class 'Box-row'—they hold the trending repos.
    repo_rows = soup.find_all('article', class_='Box-row')
    if not repo_rows:
        # If no rows are found, let's call it a day.
        raise Exception("Extraction failed: No repository rows found.")
    # We only want the top 25, because who has time for more?
    return repo_rows[:25]

def transform(html_repos):
    # This is where the magic happens. We take those raw rows and create a structured list.
    repositories = []
    for repo in html_repos:
        # Parse the developer and repository name
        # Changed from h2 to h1 since GitHub’s trending page often uses h1 for repo titles now
        title_section = repo.find('h1', class_='h3 lh-condensed')
        if not title_section:
            continue

        title_link = title_section.find('a')
        if not title_link or not title_link.get('href'):
            continue

        parts = title_link.get('href').strip('/').split('/')
        if len(parts) < 2:
            continue

        developer = parts[0].strip()
        repository_name = parts[1].strip()

        # Parse the number of stars
        stars_tag = repo.find('a', href=lambda h: h and h.endswith('/stargazers'))
        if not stars_tag:
            nbr_stars = 0
        else:
            stars_text = stars_tag.text.strip().replace(',', '')
            nbr_stars = int(stars_text) if stars_text.isdigit() else 0

        # Append the repository details
        repositories.append({
            'developer': developer,
            'repository_name': repository_name,
            'nbr_stars': nbr_stars
        })

    # Ensure we return at least one valid repository or raise an exception
    if not repositories:
        raise Exception("Transformation failed: No valid repositories were extracted.")

    return repositories

def format(repositories_data):
    # Check if the data exists, else raise an exception
    if not repositories_data:
        raise Exception("Format failed: No valid repository data to format.")

    # Format the repositories as CSV
    csv_data = "Developer,Repository Name,Number of Stars\n"
    for repo in repositories_data:
        csv_data += f"{repo['developer']},{repo['repository_name']},{repo['nbr_stars']}\n"
    return csv_data

def save_to_csv(repositories):
    # Saving the data into a file named "trending_repositories.csv"—so original.
    csv_lines = ["Developer,Repository Name,Number of Stars"]
    for repo in repositories:
        line = f"{repo['developer']},{repo['repository_name']},{repo['nbr_stars']}"
        csv_lines.append(line)

    with open("trending_repositories.csv", "w") as f:
        f.write("\n".join(csv_lines))

    print("Data has been saved to 'trending_repositories.csv'. Enjoy your fresh CSV!")

def main():
    # Let’s tie it all together with some grand orchestration.
    url = "https://storage.googleapis.com/qwasar-public/track-ds/trending_14_06_2022"
    # Step 1: Get the HTML page content
    page_content = request_github_trending(url)
    # Step 2: Extract the rows that matter
    repos_html = extract(page_content)
    # Step 3: Transform the raw HTML rows into structured data
    repositories_data = transform(repos_html)
    # Step 4: Turn that data into a CSV string
    csv_output = format(repositories_data)
    # Step 5: Print it out, because we’re proud of what we did
    print(csv_output)
    # Step 6: Save the CSV to a file for posterity
    save_to_csv(repositories_data)

if __name__ == "__main__":
    # If we run this script directly, let's run main().
    # If not, maybe someone is importing these functions elsewhere. Mysterious, I know.
    main()
