include Math

x = gets.to_i

q = sqrt(x * 2).ceil

loop {
  break if (q - 1) * q < x * 2
  q -= 1
}

puts q