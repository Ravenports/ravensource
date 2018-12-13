puts Marshal.load(Gem::Util.gunzip(File.read("/tmp/rubygems/latest_specs.4.8.gz")))
