w, a, b = gets.split.map(&:to_i)

ans = 0
if a < b
  ans = (a + w < b) ? b - (a + w) : 0;
else
  ans = (b + w < a) ? a - (b + w) : 0;
end

puts ans