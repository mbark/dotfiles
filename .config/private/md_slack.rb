#!/usr/bin/env ruby

# Read from stdin rather than file.
file_data = $stdin.read

# Upper case title
re = /^#* .+/
file_data.gsub!(re) { |match| "*#{match.upcase}*"}

# Mutate todos
file_data.gsub!("- [ ]","*ACTION ITEM:* ")

# Substitute ** for *
file_data.gsub!("**","*")

# Remove #
file_data.gsub!("\#\#\# ","")
file_data.gsub!("\#\# ","")
file_data.gsub!("\# ","")

# Add bullets since Slack doesn't support bullets and add indentation because gsub doesn't support capture groups
re = /^		- /
file_data.gsub!(re,"		• ")

re = /^	- /
file_data.gsub!(re,"	• ")

re = /^- /
file_data.gsub!(re,"• ")

# Remove mentions
file_data.gsub!("[[","")
file_data.gsub!("]]","")

# Remove highlights
file_data.gsub!("==","")

# Reformat URLs
file_data.gsub!("[","")
file_data.gsub!("]",": ")


# File.write(File.basename(file) + "_slack.txt", file_data)
puts file_data


