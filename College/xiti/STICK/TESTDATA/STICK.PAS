type arr=array[-1..1000] of longint;

var l,w,f:arr;
    i,j,n,t:longint;

function max(var a,b:longint):longint;
begin
  if a>b then
    exit(a);
  exit(b);
end;

begin
  assign(input,'STICK.IN');
  assign(output,'STICK.OUT');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do
    read(l[i],w[i]);
  for i:=1 to n-1 do
    for j:=1 to n-1 do
      if (l[j]>l[j+1]) or ((l[j]=l[j+1]) and (w[j]>w[j+1])) then
        begin
          t:=l[j];
          l[j]:=l[j+1];
          l[j+1]:=t;
          t:=w[j];
          w[j]:=w[j+1];
          w[j+1]:=t;
        end;
  fillchar(f,sizeof(f),0);
  f[1]:=1;
  for i:=2 to n do
    for j:=1 to i-1 do
      begin
        if (l[j]<=l[i]) and (w[j]<=w[i]) then
          f[i]:=max(f[i],f[j])+1
        else
          f[i]:=1;
      end;
  t:=0;
  for i:=1 to n do
    if f[i]=1 then
      inc(t);
  writeln(t);
  close(input);
  close(output);
end.