using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_14_Scope
    {
        class Difference
        {
            private int[] elements;
            public int maximumDifference;

            public Difference(int[] elements)
            {
                this.elements = elements;
            }

            public void computeDifference() {
                Array.Sort(elements);
                maximumDifference = elements[elements.Length - 1] - elements[0];
            }
        } // End of Difference Class

    }
}
