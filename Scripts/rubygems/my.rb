gs = Marshal.load Gem::Util.inflate File.read '/mech/var/cache/rubygems/specs/tzinfo-2.0.1.gemspec.rz';

puts "<minver>"
puts gs.required_ruby_version
puts "</minver>"
puts "<name>".concat(gs.name).concat("</name>")
puts "<version>"
puts gs.version
puts "</version>"
puts "<summary>".concat (gs.summary).concat("</summary>")
puts "<desc>".concat(gs.description).concat("</desc>")
puts "<home>".concat(gs.homepage).concat("</home>")
# license is a disaster (and doesn't seem to work).  Skip it.


