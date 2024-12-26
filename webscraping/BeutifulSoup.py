import requests
from bs4 import BeautifulSoup
import time
from urllib.parse import urljoin
from reportlab.lib import colors
from reportlab.lib.pagesizes import letter
from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer, Table, TableStyle
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle

def get_article_links(url):
    headers = {'User-Agent': 'Research Bot (your@email.com)'}
    links = []
    try:
        response = requests.get(url, headers=headers)
        soup = BeautifulSoup(response.text, 'html.parser')
        content_div = soup.find('div', {'id': 'mw-pages'})
        if content_div:
            links.extend([
                a.get('href') for a in content_div.find_all('a')
                if a.get('href', '').startswith('/wiki/')
                and ':' not in a.get('href', '')
            ])
    except Exception as e:
        print(f"Error getting links: {e}")
    return links

def scrape_wikipedia_page(url):
    headers = {'User-Agent': 'Research Bot (your@email.com)'}
    try:
        response = requests.get(url, headers=headers)
        soup = BeautifulSoup(response.text, 'html.parser')
        
        title = soup.find(id='firstHeading')
        content = soup.find(id='mw-content-text')
        if not title or not content:
            return None

        paragraphs = content.find_all('p')
        summary = next((p.get_text(strip=True) for p in paragraphs if p.get_text(strip=True)), '')

        return {
            'Title': title.get_text(strip=True),
            'URL': url,
            'Summary': summary,
            'References': len(soup.find_all('div', class_='reflist'))
        }
    except Exception as e:
        print(f"Error scraping page {url}: {e}")
        return None

def scrape_category(category_url, max_pages=10):
    base_url = 'https://en.wikipedia.org'
    articles = []
    visited = set()
    
    links = get_article_links(category_url)
    for link in links[:max_pages]:
        full_url = urljoin(base_url, link)
        if full_url not in visited:
            print(f"Scraping: {full_url}")
            article_data = scrape_wikipedia_page(full_url)
            if article_data:
                articles.append(article_data)
                visited.add(full_url)
            time.sleep(1)
    
    return articles

def save_to_pdf(data, filename='wikipedia_data.pdf'):
    if not data:
        print("No data to save")
        return
    
    doc = SimpleDocTemplate(filename, pagesize=letter)
    styles = getSampleStyleSheet()
    elements = []
    
    # Add title
    title_style = ParagraphStyle(
        'CustomTitle',
        parent=styles['Heading1'],
        fontSize=24,
        spaceAfter=30
    )
    elements.append(Paragraph("Wikipedia Articles", title_style))
    elements.append(Spacer(1, 20))
    
    # Add articles
    for article in data:
        # Article title
        elements.append(Paragraph(article['Title'], styles['Heading2']))
        elements.append(Spacer(1, 10))
        
        # URL
        elements.append(Paragraph(f"URL: {article['URL']}", styles['Normal']))
        elements.append(Spacer(1, 10))
        
        # Summary
        elements.append(Paragraph("Summary:", styles['Heading4']))
        elements.append(Paragraph(article['Summary'], styles['Normal']))
        elements.append(Spacer(1, 10))
        
        # References
        elements.append(Paragraph(f"Number of References: {article['References']}", styles['Normal']))
        elements.append(Spacer(1, 20))
    
    doc.build(elements)
    print(f"Saved {len(data)} articles to {filename}")

if __name__ == "__main__":
    CATEGORY_URL = "https://en.wikipedia.org/wiki/Category:Programming_languages"
    articles = scrape_category(CATEGORY_URL, max_pages=5)
    save_to_pdf(articles)