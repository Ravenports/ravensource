/^name = / {
    split($3,v,"\"")
    name = v[2]
    next
}
/^version = / {
    split($3,v,"\"")
    version = v[2]
    next
}
/^checksum = / {
    if (name == "") { next }
    if (name != target) {
       print name "-" version
    }
}
