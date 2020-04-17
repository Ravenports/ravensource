gs = Marshal.load Gem::Util.inflate File.read '/mech/var/cache/rubygems/specs/loofah-2.5.0.gemspec.rz';

puts "<minver>"
puts gs.required_ruby_version
puts "</minver>"
puts "<name>".concat(gs.name).concat("</name>")
puts "<version>"
puts gs.version
puts "</version>"
puts "<summary>".concat (gs.summary).concat("</summary>")
puts "<desc>".concat(gs.description).concat("</desc>")
if !gs.homepage.nil?
   puts "<home>".concat(gs.homepage).concat("</home>")
end
# license is a disaster (and doesn't seem to work).  Skip it.
puts "runtime"
puts gs.runtime_dependencies
puts "devel"
puts gs.development_dependencies
puts " =================== "
puts gs.inspect

