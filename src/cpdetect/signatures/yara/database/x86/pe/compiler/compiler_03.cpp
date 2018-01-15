/**
 * @file src/cpdetect/signatures/yara/database/x86/pe/compiler/compiler_03.cpp
 * @brief Database of signatures.
 * @copyright (c) 2017 Avast Software, licensed under the MIT license
 */

const char *x86PeCompiler_03 =
R"x86_pe_compiler(rule rule_101_CODE_DLL {
	meta:
		tool = "C"
		name = "CODE-DLL"
		pattern = "A1????????8B0D3442010083EC208B154042010053568B74242C578986A40000008B4618898E"
	strings:
		$1 = { A1 ?? ?? ?? ?? 8B 0D 34 42 01 00 83 EC 20 8B 15 40 42 01 00 53 56 8B 74 24 2C 57 89 86 A4 00 00 00 8B 46 18 89 8E }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_102_CODE_DLL {
	meta:
		tool = "C"
		name = "CODE-DLL"
		pattern = "A1????????8B1D????????E82200000050505050E8????????50A1"
	strings:
		$1 = { A1 ?? ?? ?? ?? 8B 1D ?? ?? ?? ?? E8 22 00 00 00 50 50 50 50 E8 ?? ?? ?? ?? 50 A1 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_103_CODE_DLL {
	meta:
		tool = "C"
		name = "CODE-DLL"
		pattern = "B001C20C00"
	strings:
		$1 = { B0 01 C2 0C 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_104_CODE_DLL {
	meta:
		tool = "C"
		name = "CODE-DLL"
		pattern = "B8????????E8????????83EC0456578B750C83FE0174??83FE02"
	strings:
		$1 = { B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 04 56 57 8B 75 0C 83 FE 01 74 ?? 83 FE 02 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_105_CODE_DLL {
	meta:
		tool = "C"
		name = "CODE-DLL"
		pattern = "B801000000C20800"
	strings:
		$1 = { B8 01 00 00 00 C2 08 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_106_CODE_DLL {
	meta:
		tool = "C"
		name = "CODE-DLL"
		pattern = "B801000000C20C00"
	strings:
		$1 = { B8 01 00 00 00 C2 0C 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_107_CODE_DLL {
	meta:
		tool = "C"
		name = "CODE-DLL"
		pattern = "B801000000C3"
	strings:
		$1 = { B8 01 00 00 00 C3 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_108_CODE_DLL {
	meta:
		tool = "C"
		name = "CODE-DLL"
		pattern = "B8010000C0C20800"
	strings:
		$1 = { B8 01 00 00 C0 C2 08 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_109_CODE_DLL {
	meta:
		tool = "C"
		name = "CODE-DLL"
		pattern = "E8????????33C0C20800"
	strings:
		$1 = { E8 ?? ?? ?? ?? 33 C0 C2 08 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_110_CODE_DLL {
	meta:
		tool = "C"
		name = "CODE-DLL"
		pattern = "E8????????68????????FF74240CFF74240CE8????????C20800"
	strings:
		$1 = { E8 ?? ?? ?? ?? 68 ?? ?? ?? ?? FF 74 24 0C FF 74 24 0C E8 ?? ?? ?? ?? C2 08 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_111_CODE_DLL {
	meta:
		tool = "C"
		name = "CODE-DLL"
		pattern = "FF742404E8"
	strings:
		$1 = { FF 74 24 04 E8 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_112_CODE_DLL {
	meta:
		tool = "C"
		name = "CODE-DLL"
		pattern = "FF742408FF7424"
	strings:
		$1 = { FF 74 24 08 FF 74 24 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_113_CODE_DLL {
	meta:
		tool = "C"
		name = "CODE-DLL"
		pattern = "FF74240CFF7424"
	strings:
		$1 = { FF 74 24 0C FF 74 24 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_114_Delphi {
	meta:
		tool = "C"
		name = "Delphi"
		version = "1.0 Unit"
		pattern = "44435531"
	strings:
		$1 = { 44 43 55 31 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_115_Delphi {
	meta:
		tool = "C"
		name = "Delphi"
		version = "2.0 Unit"
		pattern = "44435532"
	strings:
		$1 = { 44 43 55 32 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_116_Delphi {
	meta:
		tool = "C"
		name = "Delphi"
		version = "BobSoft Mini?"
		pattern = "558BEC83C4F05356B8????????E8????????33C05568????????64FF30648920B8"
	strings:
		$1 = { 55 8B EC 83 C4 F0 53 56 B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 33 C0 55 68 ?? ?? ?? ?? 64 FF 30 64 89 20 B8 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_117_Delphi {
	meta:
		tool = "C"
		name = "Delphi"
		version = "BobSoft Mini?"
		pattern = "558BEC83C4F053B8????????E8????????33C05568????????64FF30648920B8????????E8"
	strings:
		$1 = { 55 8B EC 83 C4 F0 53 B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 33 C0 55 68 ?? ?? ?? ?? 64 FF 30 64 89 20 B8 ?? ?? ?? ?? E8 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_120_FASM {
	meta:
		tool = "C"
		name = "FASM"
		extra = "Tomasz Grysztar"
		pattern = "6A00"
	strings:
		$1 = { 6A 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_121_FASM {
	meta:
		tool = "C"
		name = "FASM"
		pattern = "6A24"
	strings:
		$1 = { 6A 24 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_122_FASM {
	meta:
		tool = "C"
		name = "FASM"
		version = "1.3x"
		pattern = "6A??FF15????????A3"
	strings:
		$1 = { 6A ?? FF 15 ?? ?? ?? ?? A3 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_123_FASM {
	meta:
		tool = "C"
		name = "FASM"
		version = "1.5x"
		pattern = "6A00FF15????4000A3????4000????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????00"
	strings:
		$1 = { 6A 00 FF 15 ?? ?? 40 00 A3 ?? ?? 40 00 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_124_Free_Pascal {
	meta:
		tool = "C"
		name = "Free Pascal"
		version = "0.99.10"
		pattern = "??????????????????????????????????????E8006E00005589E58B7D0C8B750889F88B5D1029"
	strings:
		$1 = { ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? E8 00 6E 00 00 55 89 E5 8B 7D 0C 8B 75 08 89 F8 8B 5D 10 29 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_125_Free_Pascal {
	meta:
		tool = "C"
		name = "Free Pascal"
		version = "0.99.10"
		pattern = "E8006E00005589E58B7D0C8B750889F88B5D1029"
	strings:
		$1 = { E8 00 6E 00 00 55 89 E5 8B 7D 0C 8B 75 08 89 F8 8B 5D 10 29 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_126_Free_Pascal {
	meta:
		tool = "C"
		name = "Free Pascal"
		version = "1.0.10 console"
		pattern = "C605??????0001E8????0000C605??????0000E8????000050E800000000FF25??????005589E5??EC"
	strings:
		$1 = { C6 05 ?? ?? ?? 00 01 E8 ?? ?? 00 00 C6 05 ?? ?? ?? 00 00 E8 ?? ?? 00 00 50 E8 00 00 00 00 FF 25 ?? ?? ?? 00 55 89 E5 ?? EC }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_127_Free_Pascal {
	meta:
		tool = "C"
		name = "Free Pascal"
		version = "1.0.10 gui"
		pattern = "C605??????0000E8????000050E800000000FF25??????005589E5"
	strings:
		$1 = { C6 05 ?? ?? ?? 00 00 E8 ?? ?? 00 00 50 E8 00 00 00 00 FF 25 ?? ?? ?? 00 55 89 E5 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_128_Free_Pascal {
	meta:
		tool = "C"
		name = "Free Pascal"
		version = "1.0.4 DLL"
		pattern = "C605????????005589E55356578B7D08893D????????8B7D0C893D????????8B7D10893D????????E8????????5F5E5B5DC20C00"
	strings:
		$1 = { C6 05 ?? ?? ?? ?? 00 55 89 E5 53 56 57 8B 7D 08 89 3D ?? ?? ?? ?? 8B 7D 0C 89 3D ?? ?? ?? ?? 8B 7D 10 89 3D ?? ?? ?? ?? E8 ?? ?? ?? ?? 5F 5E 5B 5D C2 0C 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_129_Free_Pascal {
	meta:
		tool = "C"
		name = "Free Pascal"
		version = "1.0.4"
		pattern = "5589E5C605????????00E8????????5531ED89E0A3????????668CD5892D????????DBE3D92D????????31EDE8????????5DE8????????C9C3"
	strings:
		$1 = { 55 89 E5 C6 05 ?? ?? ?? ?? 00 E8 ?? ?? ?? ?? 55 31 ED 89 E0 A3 ?? ?? ?? ?? 66 8C D5 89 2D ?? ?? ?? ?? DB E3 D9 2D ?? ?? ?? ?? 31 ED E8 ?? ?? ?? ?? 5D E8 ?? ?? ?? ?? C9 C3 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_130_Free_Pascal {
	meta:
		tool = "C"
		name = "Free Pascal"
		version = "1.06"
		pattern = "C605????4000??E8????0000??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????00"
	strings:
		$1 = { C6 05 ?? ?? 40 00 ?? E8 ?? ?? 00 00 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_131_Free_Pascal {
	meta:
		tool = "C"
		name = "Free Pascal"
		version = "2.0.0"
		pattern = "5589E5C605????????00E8????????6A0064FF350000000089E0A3????????5531ED89E0A3????????668CD5892D????????E8????????31EDE8????????5DE8????????C9C3"
	strings:
		$1 = { 55 89 E5 C6 05 ?? ?? ?? ?? 00 E8 ?? ?? ?? ?? 6A 00 64 FF 35 00 00 00 00 89 E0 A3 ?? ?? ?? ?? 55 31 ED 89 E0 A3 ?? ?? ?? ?? 66 8C D5 89 2D ?? ?? ?? ?? E8 ?? ?? ?? ?? 31 ED E8 ?? ?? ?? ?? 5D E8 ?? ?? ?? ?? C9 C3 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_132_Free_Pascal {
	meta:
		tool = "C"
		name = "Free Pascal"
		version = "2.0.0"
		pattern = "C6050080400001E874000000C6050080400000E86800000050E800000000FF25D8A140009090909090909090909090905589E583EC04895DFCE892000000E8ED00000089C3B9??70400089DAB800000000E80A010000E8C501000089D8E83E020000E8B9010000E8540200008B5DFCC9C38D76000000000000000000000000005589E5C6051080400000E8D10300006A0064FF350000000089E0A3??7040005531ED89E0A32080"
	strings:
		$1 = { C6 05 00 80 40 00 01 E8 74 00 00 00 C6 05 00 80 40 00 00 E8 68 00 00 00 50 E8 00 00 00 00 FF 25 D8 A1 40 00 90 90 90 90 90 90 90 90 90 90 90 90 55 89 E5 83 EC 04 89 5D FC E8 92 00 00 00 E8 ED 00 00 00 89 C3 B9 ?? 70 40 00 89 DA B8 00 00 00 00 E8 0A 01 00 00 E8 C5 01 00 00 89 D8 E8 3E 02 00 00 E8 B9 01 00 00 E8 54 02 00 00 8B 5D FC C9 C3 8D 76 00 00 00 00 00 00 00 00 00 00 00 00 00 55 89 E5 C6 05 10 80 40 00 00 E8 D1 03 00 00 6A 00 64 FF 35 00 00 00 00 89 E0 A3 ?? 70 40 00 55 31 ED 89 E0 A3 20 80 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_133_FreeBASIC {
	meta:
		tool = "C"
		name = "FreeBASIC"
		version = "0.11"
		pattern = "E8????0000E801000000C35589E5"
	strings:
		$1 = { E8 ?? ?? 00 00 E8 01 00 00 00 C3 55 89 E5 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_134_FreeBASIC {
	meta:
		tool = "C"
		name = "FreeBASIC"
		version = "0.14"
		pattern = "5589E583EC08C70424??000000FF15??????00E8??FFFFFF89EC31C05DC389F65589E583EC08????????????????????????????????????????????????????5589E583EC088B4508890424FF15??????0089EC5DC3????????????????????5589E5"
	strings:
		$1 = { 55 89 E5 83 EC 08 C7 04 24 ?? 00 00 00 FF 15 ?? ?? ?? 00 E8 ?? FF FF FF 89 EC 31 C0 5D C3 89 F6 55 89 E5 83 EC 08 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 55 89 E5 83 EC 08 8B 45 08 89 04 24 FF 15 ?? ?? ?? 00 89 EC 5D C3 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 55 89 E5 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_135_FreeBASIC {
	meta:
		tool = "C"
		name = "FreeBASIC"
		version = "0.16b"
		pattern = "5589E583EC08C7042401000000FF15??????00E888FFFFFF89EC31C05DC389F65589E583EC08C7042402000000FF15??????00E868FFFFFF89EC31C05DC389F65589E583EC088B4508890424FF15??????0089EC5DC38D76008DBC27000000005589E583EC088B4508890424FF15??????0089EC5DC390909090909090909090"
	strings:
		$1 = { 55 89 E5 83 EC 08 C7 04 24 01 00 00 00 FF 15 ?? ?? ?? 00 E8 88 FF FF FF 89 EC 31 C0 5D C3 89 F6 55 89 E5 83 EC 08 C7 04 24 02 00 00 00 FF 15 ?? ?? ?? 00 E8 68 FF FF FF 89 EC 31 C0 5D C3 89 F6 55 89 E5 83 EC 08 8B 45 08 89 04 24 FF 15 ?? ?? ?? 00 89 EC 5D C3 8D 76 00 8D BC 27 00 00 00 00 55 89 E5 83 EC 08 8B 45 08 89 04 24 FF 15 ?? ?? ?? 00 89 EC 5D C3 90 90 90 90 90 90 90 90 90 90 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_136_GCC__MinGW_Dev_C {
	meta:
		tool = "C"
		name = "MinGW G++"
		version = "4.x"
		pattern = "5589E583EC????????????????????????????????????????????????????005589E583EC????????????????????????????????????????????????????0055??????????????????FF????????00"
	strings:
		$1 = { 55 89 E5 83 EC ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 00 55 89 E5 83 EC ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 00 55 ?? ?? ?? ?? ?? ?? ?? ?? ?? FF ?? ?? ?? ?? 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_137_GCC__MinGW {
	meta:
		tool = "C"
		name = "MinGW GCC"
		version = "2.x"
		pattern = "5589E5E8????????C9C3????455845"
	strings:
		$1 = { 55 89 E5 E8 ?? ?? ?? ?? C9 C3 ?? ?? 45 58 45 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_138_GCC__MinGW {
	meta:
		tool = "C"
		name = "MinGW GCC"
		version = "3.2.x"
		pattern = "5589E583EC086A006A006A006A00E80D000000B800000000C9C3909090909090FF253820400090900000000000000000FFFFFFFF00000000FFFFFFFF0000000000"
	strings:
		$1 = { 55 89 E5 83 EC 08 6A 00 6A 00 6A 00 6A 00 E8 0D 00 00 00 B8 00 00 00 00 C9 C3 90 90 90 90 90 90 FF 25 38 20 40 00 90 90 00 00 00 00 00 00 00 00 FF FF FF FF 00 00 00 00 FF FF FF FF 00 00 00 00 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_139_GCC__MinGW {
	meta:
		tool = "C"
		name = "MinGW GCC"
		version = "3.2.x DLL"
		pattern = "5589E583EC188975FC8B750C895DF883FE01745C897424048B5510895424088B5508891424E89601000083EC0C83FE0189C3742C85F6750C8B0D0030001085C9751031DB89D88B5DF88B75FC89EC5DC20C00E859000000EBEB8DB4260000000085C075D0E847000000EBC9908D742600C7042480000000E8F4050000A30030001085C0741AC70000000000A310300010E83B020000E8C6010000E975FFFFFFE8BC050000C7000C"
	strings:
		$1 = { 55 89 E5 83 EC 18 89 75 FC 8B 75 0C 89 5D F8 83 FE 01 74 5C 89 74 24 04 8B 55 10 89 54 24 08 8B 55 08 89 14 24 E8 96 01 00 00 83 EC 0C 83 FE 01 89 C3 74 2C 85 F6 75 0C 8B 0D 00 30 00 10 85 C9 75 10 31 DB 89 D8 8B 5D F8 8B 75 FC 89 EC 5D C2 0C 00 E8 59 00 00 00 EB EB 8D B4 26 00 00 00 00 85 C0 75 D0 E8 47 00 00 00 EB C9 90 8D 74 26 00 C7 04 24 80 00 00 00 E8 F4 05 00 00 A3 00 30 00 10 85 C0 74 1A C7 00 00 00 00 00 A3 10 30 00 10 E8 3B 02 00 00 E8 C6 01 00 00 E9 75 FF FF FF E8 BC 05 00 00 C7 00 0C }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_140_GCC__MinGW {
	meta:
		tool = "C"
		name = "MinGW GCC"
		version = "3.2.x DLL"
		pattern = "5589E583EC086A006A006A006A00E80D000000B800000000C9C3909090909090FF253820001090900000000000000000FFFFFFFF00000000FFFFFFFF0000000000"
	strings:
		$1 = { 55 89 E5 83 EC 08 6A 00 6A 00 6A 00 6A 00 E8 0D 00 00 00 B8 00 00 00 00 C9 C3 90 90 90 90 90 90 FF 25 38 20 00 10 90 90 00 00 00 00 00 00 00 00 FF FF FF FF 00 00 00 00 FF FF FF FF 00 00 00 00 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
})x86_pe_compiler";
