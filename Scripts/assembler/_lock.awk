/^name = / {
    split($3,v,"\"")
    name = v[2]
    next
}
/^version = / {
    split($3,v,"\"")
    version = v[2]
    if (name != target) {
       print name "-" version
    }
}
