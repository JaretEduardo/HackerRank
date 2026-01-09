using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;



class Result
{
    public static bool isAlphabeticPalindrome(string code)
    {
        int left = 0;
        int right = code.Length - 1;

        while (left < right)
        {
            if (!char.IsLetter(code[left]))
            {
                left++;
                continue;
            }

            if (!char.IsLetter(code[right]))
            {
                right--;
                continue;
            }

            if (char.ToLower(code[left]) != char.ToLower(code[right]))
            {
                return false;
            }

            left++;
            right--;

            return true;
        }
    }

}

class Solution
{
    public static void Main(string[] args)
    {
        string code = Console.ReadLine();

        bool result = Result.isAlphabeticPalindrome(code);

        Console.WriteLine((result ? 1 : 0));
    }
}
