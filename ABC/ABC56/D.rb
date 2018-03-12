n, k = gets.split.map(&:to_i)
a = gets.split.map(&:to_i).sort

ans = 0
flag = 0
n.times do |i|
  sum = a[i]
  j = 0
  loop {
    break if sum >= k || j >= n
    if j != i
      sum += a[j]
    end
    j += 1
  }
  l = 0
  loop {
    if l != i
      break if l >= n || sum - a[l] < k
      sum -= a[l]
    end
    l += 1
  }
  if flag == 0 && sum < k
    ans = n
    break
  else
    flag = 1
  end

  if sum - a[i] >= k
    ans += 1
  end
end

puts ans