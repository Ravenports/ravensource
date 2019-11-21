/^name = \"cargo\"/ {
   active = 1
   next
}
/^version =/ {
   if (active) {
     split($3,v,"\"")
     print v[2]
     exit 0
   }
}
