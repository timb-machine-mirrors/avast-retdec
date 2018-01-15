/**
 * @file src/cpdetect/signatures/yara/database/x86/pe/packer/packer_55.cpp
 * @brief Database of signatures.
 * @copyright (c) 2017 Avast Software, licensed under the MIT license
 */

const char *x86PePacker_55 =
R"x86_pe_packer(
rule rule_1496_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.33 - 0.34"
		pattern = "5751588D548358FF16725C2C037302B0003C0772022C03500FB66FFFC1ED??C1E5088D6C6D008DACAB08100000B001E32A8BD72B53088A2A33D284E90F95C652FEC68AD08D549500FF165A9F12C0D0E9740E9E1AF274E3B40033C9B501FF56AC33C9E903010000B1308B6B0803D1FF16735103D1FF16721B03D1FF16722B3C07B0097202B00B508BC72B43088A00E9D500000083C260FF16876B0C730C03D1FF16876B107303876B143C07B0087202B00B50558D9378070000FF56B05D91E9990000003C07B0077202B00A50876B0C876B10896B148D93C00B0000FF56B06A035950483BC172028BC1C1E006B1408DAC8378030000FF56A83C048BE8725C33EDD1E813ED48459145D3E580F9058D94AB78010000762B80E90433C08B53FCD12B8B120FCA2B530403C03B1372068B1340015304FF5688E2E3"
	strings:
		$1 = { 57 51 58 8D 54 83 58 FF 16 72 5C 2C 03 73 02 B0 00 3C 07 72 02 2C 03 50 0F B6 6F FF C1 ED ?? C1 E5 08 8D 6C 6D 00 8D AC AB 08 10 00 00 B0 01 E3 2A 8B D7 2B 53 08 8A 2A 33 D2 84 E9 0F 95 C6 52 FE C6 8A D0 8D 54 95 00 FF 16 5A 9F 12 C0 D0 E9 74 0E 9E 1A F2 74 E3 B4 00 33 C9 B5 01 FF 56 AC 33 C9 E9 03 01 00 00 B1 30 8B 6B 08 03 D1 FF 16 73 51 03 D1 FF 16 72 1B 03 D1 FF 16 72 2B 3C 07 B0 09 72 02 B0 0B 50 8B C7 2B 43 08 8A 00 E9 D5 00 00 00 83 C2 60 FF 16 87 6B 0C 73 0C 03 D1 FF 16 87 6B 10 73 03 87 6B 14 3C 07 B0 08 72 02 B0 0B 50 55 8D 93 78 07 00 00 FF 56 B0 5D 91 E9 99 00 00 00 3C 07 B0 07 72 02 B0 0A 50 87 6B 0C 87 6B 10 89 6B 14 8D 93 C0 0B 00 00 FF 56 B0 6A 03 59 50 48 3B C1 72 02 8B C1 C1 E0 06 B1 40 8D AC 83 78 03 00 00 FF 56 A8 3C 04 8B E8 72 5C 33 ED D1 E8 13 ED 48 45 91 45 D3 E5 80 F9 05 8D 94 AB 78 01 00 00 76 2B 80 E9 04 33 C0 8B 53 FC D1 2B 8B 12 0F CA 2B 53 04 03 C0 3B 13 72 06 8B 13 40 01 53 04 FF 56 88 E2 E3 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1497_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.35a"
		pattern = "8BF28BCA034C191C03541A20"
	strings:
		$1 = { 8B F2 8B CA 03 4C 19 1C 03 54 1A 20 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1498_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.35"
		pattern = "588D548358FF16725C2C037302B0003C0772022C03500FB66FFF????????????8D6C6D008DACAB08100000B001E32A8BD72B53088A2A33D284E90F95C652FEC68AD08D549500FF165A9F12C0D0E9740E9E1AF274E3B40033C9B501FF56AC33C9E903010000B1308B6B0803D1FF16735103D1FF16721B03D1FF16722B3C07B0097202B00B508BC72B43088A00E9D500000083C260FF16876B0C730C03D1FF16876B107303876B143C07B0087202B00B50558D9378070000FF56B05D91E9990000003C07B0077202B00A50876B0C876B10896B148D93C00B0000FF56B06A035950483BC172028BC1C1E006B1408DAC8378030000FF56A83C048BE8725C33EDD1E813ED48459145D3E580F9058D94AB78010000762B80E90433C08B53FCD12B8B120FCA2B530403C03B1372068B1340015304FF5688E2E3B104D3E003E88D531833C0554051D3E08BEA91FF56A8"
	strings:
		$1 = { 58 8D 54 83 58 FF 16 72 5C 2C 03 73 02 B0 00 3C 07 72 02 2C 03 50 0F B6 6F FF ?? ?? ?? ?? ?? ?? 8D 6C 6D 00 8D AC AB 08 10 00 00 B0 01 E3 2A 8B D7 2B 53 08 8A 2A 33 D2 84 E9 0F 95 C6 52 FE C6 8A D0 8D 54 95 00 FF 16 5A 9F 12 C0 D0 E9 74 0E 9E 1A F2 74 E3 B4 00 33 C9 B5 01 FF 56 AC 33 C9 E9 03 01 00 00 B1 30 8B 6B 08 03 D1 FF 16 73 51 03 D1 FF 16 72 1B 03 D1 FF 16 72 2B 3C 07 B0 09 72 02 B0 0B 50 8B C7 2B 43 08 8A 00 E9 D5 00 00 00 83 C2 60 FF 16 87 6B 0C 73 0C 03 D1 FF 16 87 6B 10 73 03 87 6B 14 3C 07 B0 08 72 02 B0 0B 50 55 8D 93 78 07 00 00 FF 56 B0 5D 91 E9 99 00 00 00 3C 07 B0 07 72 02 B0 0A 50 87 6B 0C 87 6B 10 89 6B 14 8D 93 C0 0B 00 00 FF 56 B0 6A 03 59 50 48 3B C1 72 02 8B C1 C1 E0 06 B1 40 8D AC 83 78 03 00 00 FF 56 A8 3C 04 8B E8 72 5C 33 ED D1 E8 13 ED 48 45 91 45 D3 E5 80 F9 05 8D 94 AB 78 01 00 00 76 2B 80 E9 04 33 C0 8B 53 FC D1 2B 8B 12 0F CA 2B 53 04 03 C0 3B 13 72 06 8B 13 40 01 53 04 FF 56 88 E2 E3 B1 04 D3 E0 03 E8 8D 53 18 33 C0 55 40 51 D3 E0 8B EA 91 FF 56 A8 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1499_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.36a"
		pattern = "ABE2E55D598B7668515946AD85C0"
	strings:
		$1 = { AB E2 E5 5D 59 8B 76 68 51 59 46 AD 85 C0 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1500_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.36b"
		pattern = "BEE011????FF36E9C30000004801????0B014B45524E454C33322E444C4C"
	strings:
		$1 = { BE E0 11 ?? ?? FF 36 E9 C3 00 00 00 48 01 ?? ?? 0B 01 4B 45 52 4E 45 4C 33 32 2E 44 4C 4C }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1501_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.36"
		pattern = "0B01????????????????????????????1810000010000000????????????????0010000000020000????????????36??????????00000000????????????????????????????????????????????????????????????????000000000A0000000000000000000000????????14000000????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????47657450726F634164647265737300FF7608FF760CBE1C01"
	strings:
		$1 = { 0B 01 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 18 10 00 00 10 00 00 00 ?? ?? ?? ?? ?? ?? ?? ?? 00 10 00 00 00 02 00 00 ?? ?? ?? ?? ?? ?? 36 ?? ?? ?? ?? ?? 00 00 00 00 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 00 00 00 00 0A 00 00 00 00 00 00 00 00 00 00 00 ?? ?? ?? ?? 14 00 00 00 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 47 65 74 50 72 6F 63 41 64 64 72 65 73 73 00 FF 76 08 FF 76 0C BE 1C 01 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1502_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.36"
		pattern = "588D548358FF16725C2C037302B0003C0772022C03500FB66FFF??????C1E5088D6C6D008DACAB08100000B001E32A8BD72B53088A2A33D284E90F95C652FEC68AD08D549500FF165A9F12C0D0E9740E9E1AF274E3B40033C9B501FF561833C9E903010000B1308B6B0803D1FF16735103D1FF16721B03D1FF16722B3C07B0097202B00B508BC72B43088A00E9D500000083C260FF16876B0C730C03D1FF16876B107303876B143C07B0087202B00B50558D9378070000FF561C5D91E9990000003C07B0077202B00A50876B0C876B10896B148D93C00B0000FF561C6A035950483BC172028BC1C1E006B1408DAC8378030000FF56143C048BE8725C33EDD1E813ED48459145D3E580F9058D94AB78010000762B80E90433C08B53FCD12B8B120FCA2B530403C03B1372068B1340015304FF563CE2E3"
	strings:
		$1 = { 58 8D 54 83 58 FF 16 72 5C 2C 03 73 02 B0 00 3C 07 72 02 2C 03 50 0F B6 6F FF ?? ?? ?? C1 E5 08 8D 6C 6D 00 8D AC AB 08 10 00 00 B0 01 E3 2A 8B D7 2B 53 08 8A 2A 33 D2 84 E9 0F 95 C6 52 FE C6 8A D0 8D 54 95 00 FF 16 5A 9F 12 C0 D0 E9 74 0E 9E 1A F2 74 E3 B4 00 33 C9 B5 01 FF 56 18 33 C9 E9 03 01 00 00 B1 30 8B 6B 08 03 D1 FF 16 73 51 03 D1 FF 16 72 1B 03 D1 FF 16 72 2B 3C 07 B0 09 72 02 B0 0B 50 8B C7 2B 43 08 8A 00 E9 D5 00 00 00 83 C2 60 FF 16 87 6B 0C 73 0C 03 D1 FF 16 87 6B 10 73 03 87 6B 14 3C 07 B0 08 72 02 B0 0B 50 55 8D 93 78 07 00 00 FF 56 1C 5D 91 E9 99 00 00 00 3C 07 B0 07 72 02 B0 0A 50 87 6B 0C 87 6B 10 89 6B 14 8D 93 C0 0B 00 00 FF 56 1C 6A 03 59 50 48 3B C1 72 02 8B C1 C1 E0 06 B1 40 8D AC 83 78 03 00 00 FF 56 14 3C 04 8B E8 72 5C 33 ED D1 E8 13 ED 48 45 91 45 D3 E5 80 F9 05 8D 94 AB 78 01 00 00 76 2B 80 E9 04 33 C0 8B 53 FC D1 2B 8B 12 0F CA 2B 53 04 03 C0 3B 13 72 06 8B 13 40 01 53 04 FF 56 3C E2 E3 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1503_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.36"
		pattern = "BE????????FF36E9C3000000"
	strings:
		$1 = { BE ?? ?? ?? ?? FF 36 E9 C3 00 00 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1504_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.37b - 0.38b"
		extra = "strip base relocation table option"
		pattern = "531833C0554051D3E08BEA91FF564C33"
	strings:
		$1 = { 53 18 33 C0 55 40 51 D3 E0 8B EA 91 FF 56 4C 33 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1505_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.37b"
		pattern = "BEB011????AD50FF7634EB7C4801????0B014C6F61644C696272617279410000181000001000000000??????0000????001000000002000004000000000037"
	strings:
		$1 = { BE B0 11 ?? ?? AD 50 FF 76 34 EB 7C 48 01 ?? ?? 0B 01 4C 6F 61 64 4C 69 62 72 61 72 79 41 00 00 18 10 00 00 10 00 00 00 00 ?? ?? ?? 00 00 ?? ?? 00 10 00 00 00 02 00 00 04 00 00 00 00 00 37 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1506_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.37"
		pattern = "0B01????????????????????????????1810000010000000????????????????0010000000020000????????????37??????????00000000????????????????????????????????????????????????????????????????000000000A0000000000000000000000????????14000000????????????????????????????????????????????????????????????????????????????????47657450726F63416464726573730000"
	strings:
		$1 = { 0B 01 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 18 10 00 00 10 00 00 00 ?? ?? ?? ?? ?? ?? ?? ?? 00 10 00 00 00 02 00 00 ?? ?? ?? ?? ?? ?? 37 ?? ?? ?? ?? ?? 00 00 00 00 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 00 00 00 00 0A 00 00 00 00 00 00 00 00 00 00 00 ?? ?? ?? ?? 14 00 00 00 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 47 65 74 50 72 6F 63 41 64 64 72 65 73 73 00 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1507_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.37"
		pattern = "588D548358FF16725C2C037302B0003C0772022C03500FB66FFF??????C1E5088D6C6D008DACAB08100000B001E32A8BD72B53088A2A33D284E90F95C652FEC68AD08D549500FF165A9F12C0D0E9740E9E1AF274E3B40033C9B501FF565033C9E903010000B1308B6B0803D1FF16735103D1FF16721B03D1FF16722B3C07B0097202B00B508BC72B43088A00E9D500000083C260FF16876B0C730C03D1FF16876B107303876B143C07B0087202B00B50558D9378070000FF56545D91E9990000003C07B0077202B00A50876B0C876B10896B148D93C00B0000FF56546A035950483BC172028BC1C1E006B1408DAC8378030000FF564C3C048BE8725C33EDD1E813ED48459145D3E580F9058D94AB78010000762B80E90433C08B53FCD12B8B120FCA2B530403C03B1372068B1340015304FF5610"
	strings:
		$1 = { 58 8D 54 83 58 FF 16 72 5C 2C 03 73 02 B0 00 3C 07 72 02 2C 03 50 0F B6 6F FF ?? ?? ?? C1 E5 08 8D 6C 6D 00 8D AC AB 08 10 00 00 B0 01 E3 2A 8B D7 2B 53 08 8A 2A 33 D2 84 E9 0F 95 C6 52 FE C6 8A D0 8D 54 95 00 FF 16 5A 9F 12 C0 D0 E9 74 0E 9E 1A F2 74 E3 B4 00 33 C9 B5 01 FF 56 50 33 C9 E9 03 01 00 00 B1 30 8B 6B 08 03 D1 FF 16 73 51 03 D1 FF 16 72 1B 03 D1 FF 16 72 2B 3C 07 B0 09 72 02 B0 0B 50 8B C7 2B 43 08 8A 00 E9 D5 00 00 00 83 C2 60 FF 16 87 6B 0C 73 0C 03 D1 FF 16 87 6B 10 73 03 87 6B 14 3C 07 B0 08 72 02 B0 0B 50 55 8D 93 78 07 00 00 FF 56 54 5D 91 E9 99 00 00 00 3C 07 B0 07 72 02 B0 0A 50 87 6B 0C 87 6B 10 89 6B 14 8D 93 C0 0B 00 00 FF 56 54 6A 03 59 50 48 3B C1 72 02 8B C1 C1 E0 06 B1 40 8D AC 83 78 03 00 00 FF 56 4C 3C 04 8B E8 72 5C 33 ED D1 E8 13 ED 48 45 91 45 D3 E5 80 F9 05 8D 94 AB 78 01 00 00 76 2B 80 E9 04 33 C0 8B 53 FC D1 2B 8B 12 0F CA 2B 53 04 03 C0 3B 13 72 06 8B 13 40 01 53 04 FF 56 10 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1508_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.37"
		pattern = "BE????????AD50FF????EB"
	strings:
		$1 = { BE ?? ?? ?? ?? AD 50 FF ?? ?? EB }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1509_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.38b"
		pattern = "BEB011????AD50FF7634EB7C4801????0B014C6F61644C696272617279410000181000001000000000??????0000????001000000002000004000000000038"
	strings:
		$1 = { BE B0 11 ?? ?? AD 50 FF 76 34 EB 7C 48 01 ?? ?? 0B 01 4C 6F 61 64 4C 69 62 72 61 72 79 41 00 00 18 10 00 00 10 00 00 00 00 ?? ?? ?? 00 00 ?? ?? 00 10 00 00 00 02 00 00 04 00 00 00 00 00 38 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1510_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.38"
		pattern = "588D548358FF16725B2C037302B0003C0772022C03500FB66FFF??????69ED000C00008DAC2B08100000B001E32A8BD72B53088A2A33D284E90F95C652FEC68AD08D549500FF165A9F12C0D0E9740E9E1AF274E3B40033C9B501FF565033C9E9FB00000004F91AC0B1308B6B0803D1FF16734903D1FF16721703D1FF16722724020409508BC72B43088A00E9CD00000083C260FF16876B0C730C03D1FF16876B107303876B142403040850558D9378070000FF56545D91E9950000002403040750876B0C876B10896B148D93C00B0000FF56546A035950483BC172028BC1C1E006B1408DAC8378030000FF564C3C048BE8725C33EDD1E813ED48459145D3E580F9058D94AB78010000762B80E90433C08B53FCD12B8B120FCA2B530403C03B1372068B1340015304FF5610"
	strings:
		$1 = { 58 8D 54 83 58 FF 16 72 5B 2C 03 73 02 B0 00 3C 07 72 02 2C 03 50 0F B6 6F FF ?? ?? ?? 69 ED 00 0C 00 00 8D AC 2B 08 10 00 00 B0 01 E3 2A 8B D7 2B 53 08 8A 2A 33 D2 84 E9 0F 95 C6 52 FE C6 8A D0 8D 54 95 00 FF 16 5A 9F 12 C0 D0 E9 74 0E 9E 1A F2 74 E3 B4 00 33 C9 B5 01 FF 56 50 33 C9 E9 FB 00 00 00 04 F9 1A C0 B1 30 8B 6B 08 03 D1 FF 16 73 49 03 D1 FF 16 72 17 03 D1 FF 16 72 27 24 02 04 09 50 8B C7 2B 43 08 8A 00 E9 CD 00 00 00 83 C2 60 FF 16 87 6B 0C 73 0C 03 D1 FF 16 87 6B 10 73 03 87 6B 14 24 03 04 08 50 55 8D 93 78 07 00 00 FF 56 54 5D 91 E9 95 00 00 00 24 03 04 07 50 87 6B 0C 87 6B 10 89 6B 14 8D 93 C0 0B 00 00 FF 56 54 6A 03 59 50 48 3B C1 72 02 8B C1 C1 E0 06 B1 40 8D AC 83 78 03 00 00 FF 56 4C 3C 04 8B E8 72 5C 33 ED D1 E8 13 ED 48 45 91 45 D3 E5 80 F9 05 8D 94 AB 78 01 00 00 76 2B 80 E9 04 33 C0 8B 53 FC D1 2B 8B 12 0F CA 2B 53 04 03 C0 3B 13 72 06 8B 13 40 01 53 04 FF 56 10 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1511_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.39 - 0.399"
		pattern = "588D548358FF16724F04FD1AD222C23C0773F6500FB66FFF??????6669ED00038DACAB0810000057B001E31F2B7B08840F0F95C4FEC48D548500FF1612C0D0E9740E2AE080E40175E633C9B501FF565033C95FE9F200000004F91AC0B13024038B6B08040803D1FF16734203D1FF16721403D1FF1672240C01508BC72B4308B1808A00EBCE83C260FF16876B0C730C03D1FF16876B107303876B1450558D9378070000FF56545D91E98F00000048876B0C50876B108D93C00B0000896B14FF56546A035950483BC172028BC1B140F6E18DAC8378030000FF564C3C048BE8725A33EDD1E883D5024891D3E580F9058D94AB78010000762B80E90433C08B53FCD12B8B120FCA2B530403C03B1372068B1340015304FF"
	strings:
		$1 = { 58 8D 54 83 58 FF 16 72 4F 04 FD 1A D2 22 C2 3C 07 73 F6 50 0F B6 6F FF ?? ?? ?? 66 69 ED 00 03 8D AC AB 08 10 00 00 57 B0 01 E3 1F 2B 7B 08 84 0F 0F 95 C4 FE C4 8D 54 85 00 FF 16 12 C0 D0 E9 74 0E 2A E0 80 E4 01 75 E6 33 C9 B5 01 FF 56 50 33 C9 5F E9 F2 00 00 00 04 F9 1A C0 B1 30 24 03 8B 6B 08 04 08 03 D1 FF 16 73 42 03 D1 FF 16 72 14 03 D1 FF 16 72 24 0C 01 50 8B C7 2B 43 08 B1 80 8A 00 EB CE 83 C2 60 FF 16 87 6B 0C 73 0C 03 D1 FF 16 87 6B 10 73 03 87 6B 14 50 55 8D 93 78 07 00 00 FF 56 54 5D 91 E9 8F 00 00 00 48 87 6B 0C 50 87 6B 10 8D 93 C0 0B 00 00 89 6B 14 FF 56 54 6A 03 59 50 48 3B C1 72 02 8B C1 B1 40 F6 E1 8D AC 83 78 03 00 00 FF 56 4C 3C 04 8B E8 72 5A 33 ED D1 E8 83 D5 02 48 91 D3 E5 80 F9 05 8D 94 AB 78 01 00 00 76 2B 80 E9 04 33 C0 8B 53 FC D1 2B 8B 12 0F CA 2B 53 04 03 C0 3B 13 72 06 8B 13 40 01 53 04 FF }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1512_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.39f"
		pattern = "5610E2E3B104D3E003E88D531833C0554051D3E08BEA91"
	strings:
		$1 = { 56 10 E2 E3 B1 04 D3 E0 03 E8 8D 53 18 33 C0 55 40 51 D3 E0 8B EA 91 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1513_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.39f"
		pattern = "FF7638AD508B3EBEF0??????6A2759F3A5FF760483C8FF"
	strings:
		$1 = { FF 76 38 AD 50 8B 3E BE F0 ?? ?? ?? 6A 27 59 F3 A5 FF 76 04 83 C8 FF }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1514_Upack {
	meta:
		tool = "P"
		name = "Upack"
		version = "0.39"
		pattern = "????????????????????E90602000033C95E870EE3F42BF18BDEAD2BD8AD03C35097AD91F3A55EAD5691011EADE2FB"
	strings:
		$1 = { ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? E9 06 02 00 00 33 C9 5E 87 0E E3 F4 2B F1 8B DE AD 2B D8 AD 03 C3 50 97 AD 91 F3 A5 5E AD 56 91 01 1E AD E2 FB }
	condition:
		for any of them : ( $ at pe.entry_point )
}
)x86_pe_packer";
