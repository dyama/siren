
# 簡易三次元ベクトルクラス
class Vec
  public
  # コンストラクタ
  def initialize(x = 0, y = 0, z = 0)
    @x = x; @y = y; @z = z
  end
  # ベクトル移動
  def +(other)
    self.class.new(@x + other.x, @y + other.y, @z + other.z)
  end
  def -(other)
    self + -other
  end
  # 配列として返す
  def to_a
    [x, y, z]
  end
  # 属性アクセサ
  public attr_accessor :x, :y, :z
end

# トライヘドロンを作るサンプル
def trihedron(origin, size)

  x = origin + Vec.new(size, 0, 0)
  y = origin + Vec.new(0, size, 0)
  z = origin + Vec.new(0, 0, size)

  # 軸
  x_axis = line origin.to_a, x.to_a
  y_axis = line origin.to_a, y.to_a
  z_axis = line origin.to_a, z.to_a

  color x_axis, 255, 0, 0
  color y_axis, 0, 255, 0
  color z_axis, 0, 0, 255

  # 帽子
  r   = size / 20
  len = size / 4
  ang = 2 * 3.141592

  x_head = cone x.to_a, [1, 0, 0], r, 0, len, ang
  y_head = cone y.to_a, [0, 1, 0], r, 0, len, ang
  z_head = cone z.to_a, [0, 0, 1], r, 0, len, ang

  color x_head, 255, 0, 0
  color y_head, 0, 255, 0
  color z_head, 0, 0, 255

  # # まとめて返す
  # objects = [x_axis, y_axis, z_axis, x_head, y_head, z_head]
  # comp = compound objects
  # objects.each do |item|
  #   erase item
  # end
  # return comp
end

# 実際の呼び出し
origin = Vec.new 0, 0, 5
tri = trihedron origin, 20


