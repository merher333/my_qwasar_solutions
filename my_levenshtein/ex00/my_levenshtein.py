def my_levenshtein(s1, s2):
   # Checking if the lenghts are equal
  if len(s1) != len(s2):
      return -1
 
  # Counting the differences
  differences = 0
  for c1, c2 in zip(s1, s2):
     if c1 != c2:
         differences += 1

  return differences

