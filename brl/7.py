import pandas as pd
import nltk
import re
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize, sent_tokenize
from nltk.stem import PorterStemmer, WordNetLemmatizer
from sklearn.feature_extraction.text import TfidfVectorizer

nltk.download('punkt')
nltk.download('stopwords')
nltk.download('wordnet')
nltk.download('averaged_perceptron_tagger')

# Read text from file
with open(r'C:\Users\Administrator\Desktop\New folder\Semester-6-Codes-main\DSBDAL\brl\sample.txt', 'r') as file:
    text = file.read()

# Sentence Tokenization
tokenized_text = sent_tokenize(text)
print("\nSentence Tokenization:\n", tokenized_text)

# Word Tokenization
tokenized_word = word_tokenize(text)
print('\nWord Tokenization:\n', tokenized_word)

# POS Tagging
pos_tagged = nltk.pos_tag(tokenized_word)
print('\nPOS Tagging:\n', pos_tagged)

# Removing stop words
stop_words = set(stopwords.words("english"))
text = re.sub('[^a-zA-Z]', ' ', text)
tokens = word_tokenize(text.lower())
filtered_text = [w for w in tokens if w not in stop_words]
print("\nTokenized Sentence:", tokens)
print("Filtered Sentence:", filtered_text)

# Stemming
ps = PorterStemmer()
stemmed_words = [ps.stem(w) for w in tokens]
print('\nStemming:', stemmed_words)

# Lemmatization
wordnet_lemmatizer = WordNetLemmatizer()
lemmatized_words = [wordnet_lemmatizer.lemmatize(w) for w in tokens]
print('\nLemmatization:', lemmatized_words)

# TF-IDF Calculation using TfidfVectorizer
documents = [text, "Another document for TF-IDF calculation"]
vectorizer = TfidfVectorizer()
X = vectorizer.fit_transform(documents)
df = pd.DataFrame(X.toarray(), columns=vectorizer.get_feature_names_out())
print('\nTF-IDF using TfidfVectorizer:')
print(df)
