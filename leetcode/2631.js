/**
 * @param {Function} fn
 * @return {Object}
 */
// 传入一个能处理元素，输出为一个字符串的函数
// 能使该函数输出的相同值的列表元素属于同一个键(键为输出值)
Array.prototype.groupBy = function (fn) {
  res = {}
  for (i = 0; i < this.length; i++) {
    t = fn(this[i])
    if (res[t] == null) {
      res[t] = []
    }
    res[t][res[t].length] = this[i]
  }

  return res
}
