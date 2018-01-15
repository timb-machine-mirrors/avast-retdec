/**
 * @file src/cpdetect/signatures/yara/database/x86/elf/compiler_02.cpp
 * @brief Database of signatures.
 * @copyright (c) 2017 Avast Software, licensed under the MIT license
 */

const char *x86ElfCompiler_02 =
R"x86_elf_compiler(rule rule_16_GCC__i686_linux_gcc
{
	meta:
		tool = "C"
		name = "GCC"
		version = "4.5"
		extra = "Ubuntu"
		pattern = "31ED5E89E183E4F050545268?0??040868?0??0408515668????0408E8????????F490909090909090909090909090905589E55383EC?4803D????0?080075??A1????0?08BB???F0?0881EB???F0?08C1FB0283EB0139D8731E8DB60000000083C001A3????0?08FF1485???F0?08A1????0?0839D872E8"
	strings:
		$1 = { 31 ED 5E 89 E1 83 E4 F0 50 54 52 68 ?0 ?? 04 08 68 ?0 ?? 04 08 51 56 68 ?? ?? 04 08 E8 ?? ?? ?? ?? F4 90 90 90 90 90 90 90 90 90 90 90 90 90 90 55 89 E5 53 83 EC ?4 80 3D ?? ?? 0? 08 00 75 ?? A1 ?? ?? 0? 08 BB ?? ?F 0? 08 81 EB ?? ?F 0? 08 C1 FB 02 83 EB 01 39 D8 73 1E 8D B6 00 00 00 00 83 C0 01 A3 ?? ?? 0? 08 FF 14 85 ?? ?F 0? 08 A1 ?? ?? 0? 08 39 D8 72 E8 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule rule_17_GCC__i686_linux_gcc
{
	meta:
		tool = "C"
		name = "GCC"
		version = "4.6"
		pattern = "31ED5E89E183E4F050545268?0??040868?0??0408515668??8?0408E8????????F490905589E55383EC04E8000000005B81C3????0?008B93FCFFFFFF85D27405E8????F?F?585BC9C39090909090905589E55383EC?4803D????0?080075??A1????0?08BB????0?0881EB????0?08C1FB0283EB0139D8731E8DB60000000083C001A3????0?08FF1485????0?08A1????0?0839D872E8"
	strings:
		$1 = { 31 ED 5E 89 E1 83 E4 F0 50 54 52 68 ?0 ?? 04 08 68 ?0 ?? 04 08 51 56 68 ?? 8? 04 08 E8 ?? ?? ?? ?? F4 90 90 55 89 E5 53 83 EC 04 E8 00 00 00 00 5B 81 C3 ?? ?? 0? 00 8B 93 FC FF FF FF 85 D2 74 05 E8 ?? ?? F? F? 58 5B C9 C3 90 90 90 90 90 90 55 89 E5 53 83 EC ?4 80 3D ?? ?? 0? 08 00 75 ?? A1 ?? ?? 0? 08 BB ?? ?? 0? 08 81 EB ?? ?? 0? 08 C1 FB 02 83 EB 01 39 D8 73 1E 8D B6 00 00 00 00 83 C0 01 A3 ?? ?? 0? 08 FF 14 85 ?? ?? 0? 08 A1 ?? ?? 0? 08 39 D8 72 E8 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule rule_18_GCC__i686_pc_linux_gnu_gcc
{
	meta:
		tool = "C"
		name = "GCC"
		version = "3.4.6"
		pattern = "31ED5E89E183E4F050545268?0????0?68?0????0?515668??????0?E8?F??????F490905589E55383EC04E8000000005B81C3??????0?8B93FCFFFFFF85D27405E8?A??F?F?585BC9C39090909090905589E583EC08803D??????0?00740CEB??83C004"
	strings:
		$1 = { 31 ED 5E 89 E1 83 E4 F0 50 54 52 68 ?0 ?? ?? 0? 68 ?0 ?? ?? 0? 51 56 68 ?? ?? ?? 0? E8 ?F ?? ?? ?? F4 90 90 55 89 E5 53 83 EC 04 E8 00 00 00 00 5B 81 C3 ?? ?? ?? 0? 8B 93 FC FF FF FF 85 D2 74 05 E8 ?A ?? F? F? 58 5B C9 C3 90 90 90 90 90 90 55 89 E5 83 EC 08 80 3D ?? ?? ?? 0? 00 74 0C EB ?? 83 C0 04 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule rule_19_GCC__i686_redhat_linux_gcc
{
	meta:
		tool = "C"
		name = "GCC"
		version = "4.5.1"
		extra = "RHEL"
		pattern = "31ED5E89E183E4F050545268?0????0868?0????08515668??????08E8????????F490909090909090909090909090905589E5538D6424?C803D??????080075??BB??????08A1??????0881EB??????08C1FB0283EB0139D8731D908D7426008D4001A3"
	strings:
		$1 = { 31 ED 5E 89 E1 83 E4 F0 50 54 52 68 ?0 ?? ?? 08 68 ?0 ?? ?? 08 51 56 68 ?? ?? ?? 08 E8 ?? ?? ?? ?? F4 90 90 90 90 90 90 90 90 90 90 90 90 90 90 55 89 E5 53 8D 64 24 ?C 80 3D ?? ?? ?? 08 00 75 ?? BB ?? ?? ?? 08 A1 ?? ?? ?? 08 81 EB ?? ?? ?? 08 C1 FB 02 83 EB 01 39 D8 73 1D 90 8D 74 26 00 8D 40 01 A3 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule rule_20_GCC__i686_redhat_linux_gcc
{
	meta:
		tool = "C"
		name = "GCC"
		version = "4.6.3"
		extra = "RHEL"
		pattern = "31ED5E89E183E4F050545268?0????0868?0????08515668?????408E8????????F49090"
	strings:
		$1 = { 31 ED 5E 89 E1 83 E4 F0 50 54 52 68 ?0 ?? ?? 08 68 ?0 ?? ?? 08 51 56 68 ?? ?? ?4 08 E8 ?? ?? ?? ?? F4 90 90 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule rule_21_GCC__i686_redhat_linux_gcc
{
	meta:
		tool = "C"
		name = "GCC"
		version = "4.7.0"
		extra = "RHEL"
		pattern = "31ED5E89E183E4F050545268?0????0?68?0????0?515668??????0?E8????????F466908B1C24C3"
	strings:
		$1 = { 31 ED 5E 89 E1 83 E4 F0 50 54 52 68 ?0 ?? ?? 0? 68 ?0 ?? ?? 0? 51 56 68 ?? ?? ?? 0? E8 ?? ?? ?? ?? F4 66 90 8B 1C 24 C3 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule rule_22_GCC__x86_64_redhat_linux_gcc
{
	meta:
		tool = "C"
		name = "GCC"
		version = "4.7.0"
		extra = "RHEL"
		pattern = "31ED4989D15E4889E24883E4F0505449C7C0?0????0?48C7C1?0????0?48C7C7??????0?E8????????F466904883EC08488B05??????0?4885C07402FFD04883C408C3"
	strings:
		$1 = { 31 ED 49 89 D1 5E 48 89 E2 48 83 E4 F0 50 54 49 C7 C0 ?0 ?? ?? 0? 48 C7 C1 ?0 ?? ?? 0? 48 C7 C7 ?? ?? ?? 0? E8 ?? ?? ?? ?? F4 66 90 48 83 EC 08 48 8B 05 ?? ?? ?? 0? 48 85 C0 74 02 FF D0 48 83 C4 08 C3 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule rule_23_GCC__x86_64_ubuntu_linux_gnu
{
	meta:
		tool = "C"
		name = "GCC"
		version = "4.6.3"
		extra = "Ubuntu"
		pattern = "31ED4989D15E4889E24883E4F0505449C7C0?0????0048C7C1?0????0048C7C7????4000E8????????F49090????????488????????????????0????????4883C408C3"
	strings:
		$1 = { 31 ED 49 89 D1 5E 48 89 E2 48 83 E4 F0 50 54 49 C7 C0 ?0 ?? ?? 00 48 C7 C1 ?0 ?? ?? 00 48 C7 C7 ?? ?? 40 00 E8 ?? ?? ?? ?? F4 90 90 ?? ?? ?? ?? 48 8? ?? ?? ?? ?? ?? ?? ?? ?0 ?? ?? ?? ?? 48 83 C4 08 C3 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule rule_24_GCC__x86_64_unknown_linux_gnu
{
	meta:
		tool = "C"
		name = "GCC"
		version = "4.7.2"
		pattern = "31ED5E89E183E4F050545268?0??0?0868?0??0?08515668????0?08E8????????F46690"
	strings:
		$1 = { 31 ED 5E 89 E1 83 E4 F0 50 54 52 68 ?0 ?? 0? 08 68 ?0 ?? 0? 08 51 56 68 ?? ?? 0? 08 E8 ?? ?? ?? ?? F4 66 90 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule rule_25_GCC
{
	meta:
		tool = "C"
		name = "GCC"
		version = "4.7.2"
		pattern = "55575653E8????????81C3????????83EC??8B93????????8B8B????????8B83????????8B2A8B93????????890C24895424??8B93????????895424??EB"
	strings:
		$1 = { 55 57 56 53 E8 ?? ?? ?? ?? 81 C3 ?? ?? ?? ?? 83 EC ?? 8B 93 ?? ?? ?? ?? 8B 8B ?? ?? ?? ?? 8B 83 ?? ?? ?? ?? 8B 2A 8B 93 ?? ?? ?? ?? 89 0C 24 89 54 24 ?? 8B 93 ?? ?? ?? ?? 89 54 24 ?? EB }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule rule_26_i386_pc_solaris2_11_gcc
{
	meta:
		tool = "C"
		name = "GCC"
		version = "3.4.3"
		extra = "Solaris 2.11"
		pattern = "6A006A008BECB8??1?060885C0740952E8?BF?FFFF83C40468?0??0508E8?EF?FFFF83C4048D05??1?06088B0085C074158D05??1?06088B0085C0740950E8?DFEFFFF83C4048B45088B15??1?060885D2750A8D5485108915??1?060883E4F083EC04528D550C8915??1?06085250E8?CFEFFFFE823000000E8??0?0000E8??0?000089042489442404E8?1FEFFFF8B442404890424E8?5FEFFFFF4558BEC525183EC048D0D??1?06088B09D1E983F90074609BD97C24008BD183E21F8A82??1?060820442400F7C100020000740580642400FD8BD183E26074188BC283E020D1E033D0C1E2056681642400FFF3660954240081E180010000741481F180010000D1E16681642400FFFC66094C2400D96C240083C404595A5DC39090C39090905589E553E8000000005B81C3??0?01005280BB??0?000000740DEB3A83C0048983??0?0000FFD28B83??0?00008B1085D275E98B831C00000085C0741283EC0C8D83??01000050E8?4F?FFFF83C410C683??0?0000018B5DFCC9C3905589E553E8000000005B81C3??0?0100508B832400000085C07419536A008D83??0?0000508D83??01000050E8?3FDFFFF83C4108B83??0?000085C0741E8B8B2C00000085C9741483EC0C8D83??0?000050E8?DFDFFFF83C41066908B5DFCC9C3909090"
	strings:
		$1 = { 6A 00 6A 00 8B EC B8 ?? 1? 06 08 85 C0 74 09 52 E8 ?B F? FF FF 83 C4 04 68 ?0 ?? 05 08 E8 ?E F? FF FF 83 C4 04 8D 05 ?? 1? 06 08 8B 00 85 C0 74 15 8D 05 ?? 1? 06 08 8B 00 85 C0 74 09 50 E8 ?D FE FF FF 83 C4 04 8B 45 08 8B 15 ?? 1? 06 08 85 D2 75 0A 8D 54 85 10 89 15 ?? 1? 06 08 83 E4 F0 83 EC 04 52 8D 55 0C 89 15 ?? 1? 06 08 52 50 E8 ?C FE FF FF E8 23 00 00 00 E8 ?? 0? 00 00 E8 ?? 0? 00 00 89 04 24 89 44 24 04 E8 ?1 FE FF FF 8B 44 24 04 89 04 24 E8 ?5 FE FF FF F4 55 8B EC 52 51 83 EC 04 8D 0D ?? 1? 06 08 8B 09 D1 E9 83 F9 00 74 60 9B D9 7C 24 00 8B D1 83 E2 1F 8A 82 ?? 1? 06 08 20 44 24 00 F7 C1 00 02 00 00 74 05 80 64 24 00 FD 8B D1 83 E2 60 74 18 8B C2 83 E0 20 D1 E0 33 D0 C1 E2 05 66 81 64 24 00 FF F3 66 09 54 24 00 81 E1 80 01 00 00 74 14 81 F1 80 01 00 00 D1 E1 66 81 64 24 00 FF FC 66 09 4C 24 00 D9 6C 24 00 83 C4 04 59 5A 5D C3 90 90 C3 90 90 90 55 89 E5 53 E8 00 00 00 00 5B 81 C3 ?? 0? 01 00 52 80 BB ?? 0? 00 00 00 74 0D EB 3A 83 C0 04 89 83 ?? 0? 00 00 FF D2 8B 83 ?? 0? 00 00 8B 10 85 D2 75 E9 8B 83 1C 00 00 00 85 C0 74 12 83 EC 0C 8D 83 ?? 01 00 00 50 E8 ?4 F? FF FF 83 C4 10 C6 83 ?? 0? 00 00 01 8B 5D FC C9 C3 90 55 89 E5 53 E8 00 00 00 00 5B 81 C3 ?? 0? 01 00 50 8B 83 24 00 00 00 85 C0 74 19 53 6A 00 8D 83 ?? 0? 00 00 50 8D 83 ?? 01 00 00 50 E8 ?3 FD FF FF 83 C4 10 8B 83 ?? 0? 00 00 85 C0 74 1E 8B 8B 2C 00 00 00 85 C9 74 14 83 EC 0C 8D 83 ?? 0? 00 00 50 E8 ?D FD FF FF 83 C4 10 66 90 8B 5D FC C9 C3 90 90 90 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule gc_x64_1
{
	meta:
		tool = "C"
		name = "gc"
		language = "Go"
		pattern = "488D7708488B3F488D0502000000FFE0488D05?9C?FFFFFFE0??????????????488B7C24088B7424108B5424144C8B5424184C8B442420B8C60100000F0589442428C3??????????????????????????488B7C24088B742410B8C70100000F05C3"
	strings:
		$1 = { 48 8D 77 08 48 8B 3F 48 8D 05 02 00 00 00 FF E0 48 8D 05 ?9 C? FF FF FF E0 ?? ?? ?? ?? ?? ?? ?? 48 8B 7C 24 08 8B 74 24 10 8B 54 24 14 4C 8B 54 24 18 4C 8B 44 24 20 B8 C6 01 00 00 0F 05 89 44 24 28 C3 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 48 8B 7C 24 08 8B 74 24 10 B8 C7 01 00 00 0F 05 C3 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule gc_x64_2
{
	meta:
		tool = "C"
		name = "gc"
		language = "Go"
		pattern = "488D742408488B3C24488D0510000000FFE0????????????????????????????488D05?9C?FFFFFFE0??????????????488B7C2408488B742410488B542418B8350100000F05730348F7D889442420C3"
	strings:
		$1 = { 48 8D 74 24 08 48 8B 3C 24 48 8D 05 10 00 00 00 FF E0 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 48 8D 05 ?9 C? FF FF FF E0 ?? ?? ?? ?? ?? ?? ?? 48 8B 7C 24 08 48 8B 74 24 10 48 8B 54 24 18 B8 35 01 00 00 0F 05 73 03 48 F7 D8 89 44 24 20 C3 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule gc_x64_3
{
	meta:
		tool = "C"
		name = "gc"
		language = "Go"
		pattern = "488D742408488B3C24488D0510000000FFE0????????????????????????????488D05?9C?FFFFFFE0??????????????4883EC2?4?8???24??4?8??C24?04C8B?4244?4?8B?C24?84?8B?424?0?8"
	strings:
		$1 = { 48 8D 74 24 08 48 8B 3C 24 48 8D 05 10 00 00 00 FF E0 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 48 8D 05 ?9 C? FF FF FF E0 ?? ?? ?? ?? ?? ?? ?? 48 83 EC 2? 4? 8? ?? 24 ?? 4? 8? ?C 24 ?0 4C 8B ?4 24 4? 4? 8B ?C 24 ?8 4? 8B ?4 24 ?0 ?8 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule gc_x64_4
{
	meta:
		tool = "C"
		name = "gc"
		language = "Go"
		pattern = "488D742408488B3C24488D0510000000FFE0????????????????????????????488D05?9C?FFFFFFE0??????????????4883EC1048896C2408488D6C2408488B6C24084883C410C3"
	strings:
		$1 = { 48 8D 74 24 08 48 8B 3C 24 48 8D 05 10 00 00 00 FF E0 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 48 8D 05 ?9 C? FF FF FF E0 ?? ?? ?? ?? ?? ?? ?? 48 83 EC 10 48 89 6C 24 08 48 8D 6C 24 08 48 8B 6C 24 08 48 83 C4 10 C3 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule gc_x64_5
{
	meta:
		tool = "C"
		name = "gc"
		language = "Go"
		pattern = "488D742408488B3C24488D0510000000FFE0????????????????????????????488D05?9C?FFFFFFE0??????????????8B7C2408B8E70000000F05C3????????488B7C24088B7424108B542414B8020000000F05483D01F0FFFF7605B8FFFFFFFF89442418C3"
	strings:
		$1 = { 48 8D 74 24 08 48 8B 3C 24 48 8D 05 10 00 00 00 FF E0 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 48 8D 05 ?9 C? FF FF FF E0 ?? ?? ?? ?? ?? ?? ?? 8B 7C 24 08 B8 E7 00 00 00 0F 05 C3 ?? ?? ?? ?? 48 8B 7C 24 08 8B 74 24 10 8B 54 24 14 B8 02 00 00 00 0F 05 48 3D 01 F0 FF FF 76 05 B8 FF FF FF FF 89 44 24 18 C3 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule gc_x64_6
{
	meta:
		tool = "C"
		name = "gc"
		language = "Go"
		pattern = "488D7708488B3F488D0502000000FFE0488D05?9C?FFFFFFE0??????????????488B7C24088B7424108B542414B8D50100000F05730348F7D889442418C3????488B7C24"
	strings:
		$1 = { 48 8D 74 24 08 48 8B 3C 24 48 8D 05 10 00 00 00 FF E0 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 48 8D 05 ?9 C? FF FF FF E0 ?? ?? ?? ?? ?? ?? ?? 8B 7C 24 08 B8 E7 00 00 00 0F 05 C3 ?? ?? ?? ?? 48 8B 7C 24 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule gc_x64_7
{
	meta:
		tool = "C"
		name = "gc"
		language = "Go"
		pattern = "488D7708488B3F488D0502000000FFE0488D05?9C?FFFFFFE0??????????????488B7C24088B7424108B542414B8D50100000F05730348F7D889442418C3????488B7C24088B742410B8D60100000F05730348F7D889442418C3????????????488B7C24"
	strings:
		$1 = { 48 8D 77 08 48 8B 3F 48 8D 05 02 00 00 00 FF E0 48 8D 05 ?9 C? FF FF FF E0 ?? ?? ?? ?? ?? ?? ?? 48 8B 7C 24 08 8B 74 24 10 8B 54 24 14 B8 D5 01 00 00 0F 05 73 03 48 F7 D8 89 44 24 18 C3 ?? ?? 48 8B 7C 24 08 8B 74 24 10 B8 D6 01 00 00 0F 05 73 03 48 F7 D8 89 44 24 18 C3 ?? ?? ?? ?? ?? ?? 48 8B 7C 24 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule gc_x86_1
{
	meta:
		tool = "C"
		name = "gc"
		language = "Go"
		pattern = "83EC088B4424088D5C240C890424895C2404E809000000CD03??????????????E9"
	strings:
		$1 = { 83 EC 08 8B 44 24 08 8D 5C 24 0C 89 04 24 89 5C 24 04 E8 09 00 00 00 CD 03 ?? ?? ?? ?? ?? ?? ?? E9 }
	condition:
		for any of them : ( $ at elf.entry_point )
})x86_elf_compiler";
