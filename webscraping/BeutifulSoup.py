import requests
from bs4 import BeautifulSoup
import csv
import time
from urllib.parse import urljoin

def scrape_wikipedia_page(url):
    headers = {'User-Agent': 'Research Bot (your@email.com)'}
    try:
        response = requests.get(url, headers=headers)
        response.raise_for_status()
        soup = BeautifulSoup(response.text, 'html.parser')
        
        content = soup.find(id='mw-content-text')
        if not content:
            return None
            
        # Extract main content
        article_data = {
            'Title': soup.find(id='firstHeading').get_text(strip=True),
            'URL': url,
            'Summary': content.find('p', class_=lambda x: x is None).get_text(strip=True),
            'Categories': [cat.get_text() for cat in soup.select('div#mw-normal-catlinks ul li')],
            'References': len(soup.find_all('div', class_='reflist'))
        }
        
        # Extract links to other Wikipedia pages
        article_data['Internal_Links'] = [
            urljoin('https://en.wikipedia.org', a['href'])
            for a in content.find_all('a', href=True)
            if a['href'].startswith('/wiki/')
            and ':' not in a['href']
            and not a['href'].startswith('/wiki/Main_Page')
        ]
        
        return article_data
        
    except Exception as e:
        print(f"Error scraping {url}: {e}")
        return None

def scrape_wiki_category(category_url, max_pages=10):
    articles = []
    visited = set()
    
    try:
        headers = {'User-Agent': 'Research Bot (your@email.com)'}
        response = requests.get(category_url, headers=headers)
        soup = BeautifulSoup(response.text, 'html.parser')
        
        links = [
            urljoin('https://en.wikipedia.org', a['href'])
            for a in soup.select('div.mw-category a')
            if ':' not in a['href']
        ][:max_pages]
        
        for link in links:
            if link not in visited:
                print(f"Scraping: {link}")
                article_data = scrape_wikipedia_page(link)
                if article_data:
                    articles.append(article_data)
                visited.add(link)
                time.sleep(1)  # Rate limiting
                
    except Exception as e:
        print(f"Error in category scraping: {e}")
    
    return articles

def save_to_csv(data, filename='wikipedia_data.csv'):
    if not data:
        return
    
    with open(filename, 'w', newline='', encoding='utf-8') as file:
        writer = csv.DictWriter(file, fieldnames=data[0].keys())
        writer.writeheader()
        writer.writerows(data)

if __name__ == "__main__":
    CATEGORY_URL = "https://en.wikipedia.org/wiki/Category:Programming_languages"  # Example
    MAX_PAGES = 5
    
    articles = scrape_wiki_category(CATEGORY_URL, MAX_PAGES)
    save_to_csv(articles)