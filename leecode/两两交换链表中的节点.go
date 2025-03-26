/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func swapPairs(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	nxt := head.Next
	head.Next = swapPairs(head.Next.Next)
	nxt.Next = head
	return nxt
}
