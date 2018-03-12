s = gets.split

if s[0] == 'H'
  puts s[1]
else
  if s[1] == 'H'
    puts 'D'
  else
    puts 'H'
  end
end