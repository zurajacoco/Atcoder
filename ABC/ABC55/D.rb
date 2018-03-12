n = gets.to_i
s = gets

pattern = [{"SS"=>'S', "SW"=>'W', "WS"=>'W', "WW"=>'S'}, {"SS"=>'W', "SW"=>'S', "WS"=>'S', "WW"=>'W'}]
pt = (s[0] == 'o') ? 0 : 1

keys = ["SS", "SW", "WS", "WW"]
ok = false
4.times do |i|
  ans = keys[i].dup

  1.upto(n - 1) do |j|
    if s[j] == 'o'
      ans << pattern[0][ans[-2]+ans[-1]]
    else
      ans << pattern[1][ans[-2]+ans[-1]]
    end
  end

  if pattern[pt][keys[i]] == ans[n - 1] && ans[n] == ans[0]
    ok = true
    puts ans[0..(n - 1)]
    break
  end
end

puts (-1) unless ok