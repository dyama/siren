# IJN destroyer Shimakaze

$ap = [0, 0, 0]
$yaxis = [0, 1, 0]

# lines of Hull
wl = [
  [[1.0,0,6],[1,1,6],[3,2,6],[6,3,6],[10,4,6],[13,4.5,6],[20,5.0,6],[30,5.5,6],[40,5.5,6],[50,5.5,6],[60,5.5,6],[70,5.5,6],[80,5.5,6],[90,5.1,6.0],[100,4.5,6],[105,4.1-0.00,6],[110,3.5-0.00,6],[113,2.9-0.00,6],[116,2.0-0.00,6],[119-0.0,0.9-0.00,6],[120+0.9,0,6]],
  [[0.7,0,5],[1,1,5],[3,2,5],[6,3,5],[10,4,5],[13,4.5,5],[20,5.0,5],[30,5.5,5],[40,5.5,5],[50,5.5,5],[60,5.5,5],[70,5.5,5],[80,5.5,5],[90,5.1,5.0],[100,4.5,5],[105,4.1-0.10,5],[110,3.5-0.10,5],[113,2.9-0.10,5],[116,2.0-0.12,5],[119-0.2,0.9-0.10,5],[120+0.4,0,5]],
  [[0.5,0,4],[1,1,4],[3,2,4],[6,3,4],[10,4,4],[13,4.5,4],[20,5.0,4],[30,5.5,4],[40,5.5,4],[50,5.5,4],[60,5.5,4],[70,5.5,4],[80,5.5,4],[90,5.1,4,0],[100,4.5,4],[105,4.1-0.16,4],[110,3.5-0.16,4],[113,2.9-0.18,4],[116,2.0-0.23,4],[119-0.4,0.9-0.16,4],[120+0.0,0,4]],
  [[0.3,0,3],[1,1,3],[3,2,3],[6,3,3],[10,4,3],[13,4.5,3],[20,5.0,3],[30,5.5,3],[40,5.5,3],[50,5.5,3],[60,5.5,3],[70,5.5,3],[80,5.5,3],[90,5.1,3.0],[100,4.5,3],[105,4.1-0.20,3],[110,3.5-0.20,3],[113,2.9-0.24,3],[116,2.0-0.33,3],[119-0.6,0.9-0.20,3],[120-0.3,0,3]],
  [[0.2,0,2],[1,1,2],[3,2,2],[6,3,2],[10,4,2],[13,4.5,2],[20,5.0,2],[30,5.5,2],[40,5.5,2],[50,5.5,2],[60,5.5,2],[70,5.5,2],[80,5.5,2],[90,5.1,2.0],[100,4.5,2],[105,4.1-0.22,2],[110,3.5-0.22,2],[113,2.9-0.29,2],[116,2.0-0.42,2],[119-0.8,0.9-0.22,2],[120-0.5,0,2]],
  [[0.1,0,1],[1,1,1],[3,2,1],[6,3,1],[10,4,1],[13,4.5,1],[20,5.0,1],[30,5.5,1],[40,5.5,1],[50,5.5,1],[60,5.5,1],[70,5.5,1],[80,5.5,1],[90,5.1,1.0],[100,4.5,1],[105,4.1-0.23,1],[110,3.5-0.23,1],[113,2.9-0.33,1],[116,2.0-0.50,1],[119-1.0,0.9-0.23,1],[120-0.6,0,1]],
  [[0.0,0,0],[1,1,0],[3,2,0],[6,3,0],[10,4,0],[13,4.5,0],[20,5.0,0],[30,5.5,0],[40,5.5,0],[50,5.5,0],[60,5.5,0],[70,5.5,0],[80,5.5,0],[90,5.1,0.0],[100,4.5,0],[105,4.1-0.24,0],[110,3.5-0.24,0],[113,2.9-0.35,0],[116,2.0-0.56,0],[119-1.2,0.9-0.24,0],[120-0.7,0,0]]
]

lines = []
wl.each do |n|
    lines.push(polyline(n))
end

hullp = loft lines

ltopp = polyline(wl[0] + [wl[0][0]])
gtopp = wire([ltopp])
topp  = wire2plane(gtopp)

lbtmp = polyline(wl.last + [wl.last[0]])
gbtmp = wire([lbtmp])
btmp  = wire2plane(gbtmp)

lines.each do |n|
    erase n
end
erase [ltopp, gtopp, lbtmp, gbtmp]

hulls = mirror(copy(hullp), $ap, $yaxis)
tops  = mirror(copy(topp),  $ap, $yaxis)
btms  = mirror(copy(btmp),  $ap, $yaxis)

# Upperdeck line
def updk_mold_solid
    n = -9
    a = 10
    ul = [[0,n,2.5],[83,n,2.5],[85,n,4.8],[100,n,4.8],[110,n,5.1],[116,n,5.5],[122,n,6],
        [122,n,a],[0,n,a],[0,n,2.5]]

    hoge = polyline ul
    fuga = wire([hoge])
    piyo = wire2plane(fuga)
    result = sweep(piyo, [0, -n*2, 0])

    erase [hoge, fuga, piyo]

    return result
end

parts = [hullp, topp, btmp, hulls, tops, btms]

shell = sew parts
hull = shell2solid shell
sol = updk_mold_solid
cut hull, sol

erase [shell, hull, sol]
erase parts

fit

# 零式五連想魚雷発射管
def torpedo

    r360 = 6.28318531

    # 九三式酸素魚雷 L9000 x R610mm
    len = 10.0
    r   = 0.7/2
    z   = 1.0
    dir = [1, 0, 0]

    comp = []

    # 発射管
    (0...5).each do |i|
        y = (i-2)*0.9
        comp.push(cylinder([0,y,z],           dir, r,     len,  r360))
        comp.push(cylinder([len/15*1,y,z],    dir, r*1.2, 0.1,  r360))
        comp.push(cylinder([len/15*2,y,z],    dir, r*1.2, 0.1,  r360))
        comp.push(cylinder([len/15*3,y,z],    dir, r*1.2, 0.1,  r360))
        comp.push(cylinder([len/15*4,y,z],    dir, r*1.2, 0.1,  r360))
        comp.push(cylinder([len-0.4,y,z],     dir, r*1.2, 0.35, r360))
        comp.push(cylinder([len-2,y-0.2,z+r], dir, 0.1,   1.85, r360))
    end

    # 発射管制室 本体
    y = 2.5
    z = 2.0
    fx = 0.8
    fy = 0.4
    x = len/15*4
    a1 = wire([polyline([[x,-y,0],    [x+fx,-y+fy,z*0.9],  [x+fx,y-fy,z*0.9],  [x,y,0],     [x,-y,0]])])
    x = len/15*6
    a2 = wire([polyline([[x,-y*1.2,0],[x,-y+fy,z],         [x,y-fy,z],         [x,y*1.2,0], [x,-y*1.2,0]])])
    x = len/15*12
    a3 = wire([polyline([[x,-y*1.1,0],[x,-y+fy,z],         [x,y-fy,z],         [x,y*1.1,0], [x,-y*1.1,0]])])
    x = len/15*14
    a4 = wire([polyline([[x,-y,0],    [x-fx/2,-y+fy,z*0.8],[x-fx/2,y-fy,z*0.8],[x,y,0],     [x,-y,0]])])
    ws = [a1, a2, a3, a4]
    comp.push(loft(ws))
    comp.push(wire2plane(a1))
    comp.push(wire2plane(a4))
    erase ws

    # 照準窓
    x = len/15*4+1
    zs = 1.4
    zu = 1.7
    a = polyline([[x,-1,zs],[x,-1,zu],[x,1,zu],[x,1,zs]]);
    comp.push(sweep(a,[0.5,0,0]))
    erase a

    # 窓
    a = box([0.5,0.5,0.3],[x-0.5,1.4,1.6])
    comp.push(a)
    b = copy(a)
    comp.push(mirror(b,[0,0,0],[0,-1,0]))

    # 出入口(サイド)
    w = 6
    a = polyline([[6,-w/2,0], [6,-w/2,1.8], [6.8,-w/2,1.8], [6.8,-w/2,0]])
    comp.push(sweep(a,[0,w,0]))
    erase a

    # マンホール
    x = len/15*7
    comp.push(cylinder([x,0,2],[0,0,1],0.3,0.3,r360))
    comp.push(cylinder([x,0,2],[0,0,1],0.4,0.2,r360))

    # 手すり
    xa = len/15*6
    xf = len/15*12
    z  = 2.0
    h  = 1.0
    y  = 2.1
    r  = 0.03
    (6..12).each do |i|
        comp.push(cylinder([len/15*i, y,z],[0,0,1],r,h,r360))
        comp.push(cylinder([len/15*i,-y,z],[0,0,1],r,h,r360))
    end
    comp.push(cylinder([xa,0.0,z],[0,0,1],r,h,r360))
    (1...3).each do |i|
        n = i * 0.6
        comp.push(cylinder([xa, n,z],[0,0,1],r,h,r360))
        comp.push(cylinder([xa,-n,z],[0,0,1],r,h,r360))
    end
    comp.push(cylinder([xa, y,z+h],[1,0,0],r,xf-xa,r360))
    comp.push(cylinder([xa,-y,z+h],[1,0,0],r,xf-xa,r360))
    comp.push(cylinder([xa,-y,z+h],[0,1,0],r,y*2,r360))

    # 上の構造物
    comp.push(box([4,0.2,0.7],[len/15*7, 1.2,z-0.5]))
    comp.push(box([4,0.2,0.7],[len/15*7,-1.2,z-0.5]))

    # サイドの構造物
    y = 2.95
    comp.push(box([0.4,y*2,0.5],[len/15*7,-y,0.3]))

    # 台座
    comp.push(cylinder([5.25,0,0],[0,0,-1],1.5,0.2,r360))

    compound comp

end
