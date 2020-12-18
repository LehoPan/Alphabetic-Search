import os
import sys

"""
with open(os.path.join(sys.path[0], "test_words.txt"), "r") as reader:
   word = (reader.readline())
   print(word)


with open(os.path.join(sys.path[0], "test_words.txt"), "r") as reader:
   for x in reader:
      print(x)

f = open("a.txt", "r")
"""

reader = open(os.path.join(sys.path[0], "raw_words.txt"), "r")
writer = open(os.path.join(sys.path[0], "newWords.txt"), "w")

for x in reader:
   if x.isupper():
      x = x
   else:
      x = x.lower()
      writer.write(x)

reader.close()
writer.close()
