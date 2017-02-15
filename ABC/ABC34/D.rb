n, k = gets.split().map(&:to_i)

v = [];
n.times do |i|
  w, per = gets.split().map(&:to_f)
  v << [w, per / 100.0]
end

ok = 0.0
ng = 1.0
loop{
  solt = []
  mid = (ok + ng) / 2.0
  n.times do |i|
    tmp = (v[i][1] - mid) * v[i][0]
    solt << tmp
  end

  solt.sort! {|a, b| b <=> a}

  sum = 0.0
  k.times do |i|
    sum += solt[i]
  end

  if sum >= 0.0
    ok = mid
  else
    ng = mid
  end

  break if ng - ok < 1e-9
}

puts ok * 100.0
