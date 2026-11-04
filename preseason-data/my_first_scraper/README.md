# Welcome to My First Scraper
***

## Task
Alright, imagine this: you're on GitHub, looking at all the shiny trending repositories, but you're like, "Man, I wish I had a robot to gather all this for me." 
That's where this project comes in! The challenge was to create a script that collects the top 25 trending repos without losing our sanity in a sea of HTML.

## Description
This Python script is basically your new data buddy. It fetches the top trending repositories from GitHub, extracts their juicy details (developer’s name, repository name, and number of stars), and then packages it all neatly into a CSV file—because who doesn’t love a good spreadsheet?
Using requests, the script politely asks GitHub for the HTML. Then, with the help of BeautifulSoup, it sifts through the chaos like a librarian on a mission. The result? A clean CSV file that’s easy to use and perfect for anyone who’s nosy about GitHub trends.
P.S. It doesn't hack GitHub. It just asks nicely.

## Installation
No complicated rituals or sacrifices required. Just follow these steps:
1. Clone this masterpiece :
    git clone <repository-url>
2. Enter the magical folder:
    cd project-folder/ex00
3. Make sure Python knows what it's doing
    pip install requests beautifulsoup4

## Usage
It’s as easy as making instant noodles. Run the script, sit back, and let the magic happen:
    python my_first_scraper.py
When it’s done, you’ll find your results saved in a file called trending_repositories.csv. Open it up to see the top trending repositories neatly organized.

```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
