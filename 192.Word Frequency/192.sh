cat words.txt | tr [:space:] "\n" | sed '/^$/d' | tr '[:upper:]' '[:lower:]'|sort|uniq -c|sort -nr | awk '{ print $2,$1}'
#awk '{  for(i=1; i <= NF; i++) a[$i] += 1}  END { for(i in a)  print i, a[i] | "sort -r -n -k2" }'  words.txt
