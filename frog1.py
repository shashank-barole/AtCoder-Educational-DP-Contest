N = int(input())
hs = list(map(int,input().split()))

ans = [float('inf')]*(N+1)
ans[0]=0
for i in range(N):
    if (i+1)<N:
        ans[i+1] = min(ans[i+1],ans[i]+abs(hs[i+1]-hs[i]))
    if (i+2)<N:
        ans[i+2] = min(ans[i+2],ans[i]+abs(hs[i+2]-hs[i]))
print(ans[N-1])