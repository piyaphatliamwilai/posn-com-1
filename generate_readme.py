import os
import urllib.parse
from collections import defaultdict

base_dir = '.'  # repo root
readme_file = 'README.md'

content = "### POSN COM 🤑🤑🤑\n\n"

# Skip hidden folders
programmers = [f for f in os.listdir(base_dir)
               if os.path.isdir(f) and not f.startswith('.')]
programmers.sort()

# Collect files per topic across all programmers
topics_dict = defaultdict(list)

for programmer in programmers:
    programmer_path = os.path.join(base_dir, programmer)
    topics = [t for t in os.listdir(programmer_path)
              if os.path.isdir(os.path.join(programmer_path, t)) and not t.startswith('.')]
    topics.sort()
    
    for topic in topics:
        topic_path = os.path.join(programmer_path, topic)
        files = [f for f in os.listdir(topic_path)
                 if os.path.isfile(os.path.join(topic_path, f)) and not f.startswith('.')]
        files.sort()
        
        for file in files:
            file_path = urllib.parse.quote(os.path.join(programmer, topic, file))
            # New format: [File Name (Programmer)](directory)
            topics_dict[topic].append(f"[{file} ({programmer})]({file_path})")

# Write topics in order
for topic in sorted(topics_dict.keys()):
    content += f"{topic}\n"
    for entry in topics_dict[topic]:
        content += f"- {entry}\n"
    content += "\n"

# Write to README.md
with open(readme_file, 'w', encoding='utf-8') as f:
    f.write(content)
