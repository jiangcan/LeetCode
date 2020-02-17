#pragma once
#include <iostream>
#include "windows.h"
#include <string>
#include <unordered_map>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
	//
	//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
	//
	//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
	//
	//示例：
	//
	//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
	//输出：7 -> 0 -> 8
	//原因：342 + 465 = 807
	//
	//来源：力扣（LeetCode）
	//链接：https ://leetcode-cn.com/problems/add-two-numbers
	//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* l3 = new ListNode(0);
		ListNode* ret = &*l3;

		while (true)
		{

			if (l1 != NULL)
			{

				l3->val += l1->val;
				l1 = l1->next;

			}
			if (l2 != NULL)
			{
				l3->val += l2->val;
				l2 = l2->next;

			}
			if (l3->val >= 10)
			{
				l3->next = new ListNode(1);
				l3->val = l3->val - 10;

			}

			if (l1 == NULL && l2 == NULL)
			{

				return ret;
			}
			if (l3->next == NULL)
			{
				l3->next = new ListNode(0);
			}
			l3 = l3->next;
		}
	}

	//	给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
	//
	//		示例 1 :
	//
	//输入: "abcabcbb"
	//输出 : 3
	//解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
	//示例 2 :
	//
	//	输入 : "bbbbb"
	//	输出 : 1
	//	解释 : 因为无重复字符的最长子串是 "b"，所以其长度为 1。
	//	示例 3 :
	//
	//	输入 : "pwwkew"
	//	输出 : 3
	//	解释 : 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
	//	请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
	//
	//	来源：力扣（LeetCode）
	//	链接：https ://leetcode-cn.com/problems/longest-substring-without-repeating-characters
	//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
	int lengthOfLongestSubstring(std::string s) {
		int vmap[0xff];
		memset(vmap, -1, sizeof(vmap));
		int left = -1;
		char* p = &s[0];
		int res = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			left = max(left, vmap[*p]);
			vmap[*p] = i;

			++p;
			res = max(res, i - left);
		}
		return res;

	}
	//	给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
	//
	//		示例 1 :
	//
	//输入: 123
	//输出 : 321
	//示例 2 :
	//
	//	输入 : -123
	//	输出 : -321
	//	示例 3 :
	//
	//	输入 : 120
	//	输出 : 21
	//	注意 :
	//
	//	假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231, 231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
	//
	//	来源：力扣（LeetCode）
	//	链接：https ://leetcode-cn.com/problems/reverse-integer
	//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
	int reverse(int x)
	{
		int des[10];
		memset(des, 0, sizeof(des));
		int maxInt[] = { 2, 1, 4, 7, 4, 8, 3, 6, 4, 7 };
		if (-2147483648 == x)
		{
			return 0;
		}
		//判断负数
		bool b = x < 0;
		x = abs(x);
		int l = 0;
		for (size_t i = 0; i < 10; i++)
		{
			des[i] = (x % 10);
			x /= 10;
			std::cout << des[i]<<std::endl;
			if (x == 0)
			{
				l = i + 1;
				break;
			}
		}
		std::cout <<l<< std::endl;
		int res = 0;
		if (l==10)
		{
			for (size_t i = 0; i < 10; i++)
			{

				if (des[i] > maxInt[i])
				{
					return 0;
				}
				if (des[i] < maxInt[i])
				{
					break;
				}
			}
		}
		for (size_t i = 0; i < l; i++)
		{
			res += des[i] * pow(10, l-1-i);

		}
	

		if (b)
		{
			res = -res;
		}
		return res;

	}


};