// 序列式容器 STL 容器将运用最广的数据结构实现出来
// 序列式容器   关联式容器

// 衍生，并非派生关系，而是内含关系
// stack 和 deque 只是将 deque改头换面而成，技术上被归类为一种配接器 adapter

// vector 是动态空间，随着元素的加入，内部机制会自行扩充空间以容纳新元素

// 一个vector的容量永远大于或等于其大小。一旦容量等于大小，便是满载
// 运用 start，finish，end_of_storage 三个迭代器，便可以轻易提供收尾标示，大小，容量，空容器判断
