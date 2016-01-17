package main

import (
	"container/list"
	"fmt"
)

func addTwoNumbers(a *list.List, b *list.List) (c *list.List) {

	d := list.New()

	for e1, e2 := a.Front(), b.Front(); e1 != nil && e2 != nil; e1, e2 = e1.Next(), e2.Next() {

		v1 := e1.Value.(int) //e1.Value 为 interface{}
		v2 := e2.Value.(int)

		value := (v1 + v2) % 10

		d.PushBack(value)

		if e1.Next() == nil {

			for e2.Next() != nil {

				d.PushBack(e2.Next().Value.(int))
				e2 = e2.Next()
			}
		}

		if e2.Next() == nil {

			for e1.Next() != nil {

				d.PushBack(e1.Next().Value.(int))
				e1 = e1.Next()
			}

		}

	}

	return d
}

func main() {

	a := list.New()
	b := list.New()
	c := list.New()

	a.PushBack(1)
	a.PushBack(2)
	a.PushBack(9)
	a.PushBack(4)

	b.PushBack(3)
	b.PushBack(7)

	c = addTwoNumbers(a, b)

	for e := c.Front(); e != nil; e = e.Next() {

		fmt.Println(e.Value)
	}
}
