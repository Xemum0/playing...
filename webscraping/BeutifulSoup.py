import requests
from bs4 import BeautifulSoup
import csv
import os

# Function to scrape a single page
def scrape_page(url):
    articles_data = []
    try:
        response = requests.get(url)
        response.raise_for_status()  # Raise an error for bad HTTP responses
        soup = BeautifulSoup(response.text, 'html.parser')

        # Find all article sections (modify selectors based on the website structure)
        articles = soup.select('.article')  # Replace '.article' with the actual class or tag
        for article in articles:
            # Extract article title
            title_tag = article.find('h2', class_='article-title')
            title = title_tag.get_text(strip=True) if title_tag else 'No Title'

            # Extract link
            link = title_tag.find('a')['href'] if title_tag and title_tag.find('a') else 'No Link'

            # Extract image URL
            img_tag = article.find('img')
            image_url = img_tag['src'] if img_tag else 'No Image'

            # Extract publication date
            date_tag = article.find('time', class_='pub-date')
            pub_date = date_tag.get_text(strip=True) if date_tag else 'No Date'

            # Add the data to the list
            articles_data.append({
                'Title': title,
                'Link': link,
                'Image URL': image_url,
                'Publication Date': pub_date
            })
    except requests.exceptions.RequestException as e:
        print(f"Error fetching URL {url}: {e}")
    
    return articles_data

# Function to handle pagination and scrape multiple pages
def scrape_website(base_url, max_pages=5):
    all_articles = []
    for page_num in range(1, max_pages + 1):
        print(f"Scraping page {page_num}...")
        page_url = f"{base_url}?page={page_num}"  # Modify based on site's pagination
        page_data = scrape_page(page_url)
        all_articles.extend(page_data)

    return all_articles

# Function to save data to a CSV file
def save_to_csv(data, filename='scraped_data.csv'):
    if not data:
        print("No data to save.")
        return

    keys = data[0].keys()
    with open(filename, mode='w', newline='', encoding='utf-8') as file:
        writer = csv.DictWriter(file, fieldnames=keys)
        writer.writeheader()
        writer.writerows(data)

    print(f"Data saved to {filename}")

# Main program
if __name__ == "__main__":
    BASE_URL = "https://example.com/news"  
    MAX_PAGES = 3  

    print("Starting web scraping...")
    scraped_articles = scrape_website(BASE_URL, MAX_PAGES)
    
    print(f"Scraped {len(scraped_articles)} articles.")
    save_to_csv(scraped_articles)
    print("Web scraping complete.")