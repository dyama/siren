#!/usr/bin/env ruby
# -*- mode:ruby; coding:utf-8 -*-

# å`èÛ ÉNÉâÉX
class Shape

  attr_accessor :id

  def type
    Kernel::type @id
  end

  def bndbox
    Kernel::bndbox @id
  end

  def expl(type)
    if !block_given?
      raise ""
    end
    Kernel::explode(type, self).each do |item|
      yield item
    end
  end

  def translate(vector)
    Kernel::translate self, vector
  end

  def rotate(center, normal, angle)
    Kernel::rotate self, center, normal, angle
  end

  def scale(scale, center)
    Kernel::scale self, scale, center
  end

  def mirror(center, normal)
    Kernel::mirror self, center, normal
  end

end

