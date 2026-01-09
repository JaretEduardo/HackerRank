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
    public static int countResponseTimeRegressions(List<int> responseTimes)
    {
        int count = 0;
        
        if (responseTimes.Count == 0 || responseTimes.Count == 1) return count;
        
        long runingSum = responseTimes[0];
        
        for (int i = 1; i < responseTimes.Count; i++)
        {
            int value = responseTimes[i];
            double average = (double)runingSum / i;
            
            if (value > average)
            {
                count++;
            }
            
            runingSum += value;
        }
        
        return count;
    }

}

class Solution
{
    public static void Main(string[] args)
    {
        int responseTimesCount = Convert.ToInt32(Console.ReadLine().Trim());

        List<int> responseTimes = new List<int>();

        for (int i = 0; i < responseTimesCount; i++)
        {
            int responseTimesItem = Convert.ToInt32(Console.ReadLine().Trim());
            responseTimes.Add(responseTimesItem);
        }

        int result = Result.countResponseTimeRegressions(responseTimes);

        Console.WriteLine(result);
    }
}
