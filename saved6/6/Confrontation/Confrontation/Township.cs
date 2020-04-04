﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace Confrontation
{
    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Unicode)]
    public struct Township
    {
        public int Population;
        public int Code;
        public int Budget;

        public int SchoolCount;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 10)]
        public string Name;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 10)]
        public string Region;

    }
}
