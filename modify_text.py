import os
import sys

"""
Opens to read words from raw words file, then opens output to new words file.
"""

reader = open(os.path.join(sys.path[0], "raw_words.txt"), "r")
writer = open(os.path.join(sys.path[0], "newWords.txt"), "w")

"""
Only transfers words that are not acronyms into the new file, and changes all letters to lowercase.
"""

for x in reader:
   if x.isupper():
      x = x
   else:
      x = x.lower()
      writer.write(x)

reader.close()
writer.close()
