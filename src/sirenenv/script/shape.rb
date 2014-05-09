#!/usr/bin/env ruby
# -*- mode:ruby; coding:utf-8 -*-

# 形状 クラス
class Shape

  attr_accessor :id

  def type
    Kernel::type(@id)
  end

  def bndbox
    Kernel::bndbox(@id)
  end

end

