puts Marshal.load(Gem.gunzip(File.read("/tmp/rubygems/latest_specs.4.8.gz")))
