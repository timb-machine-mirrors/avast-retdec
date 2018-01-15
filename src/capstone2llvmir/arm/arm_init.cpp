/**
 * @file src/capstone2llvmir/arm/arm_init.cpp
 * @brief Initializations for ARM implementation of @c Capstone2LlvmIrTranslator.
 * @copyright (c) 2017 Avast Software, licensed under the MIT license
 */

#include "retdec/capstone2llvmir/arm/arm.h"

namespace retdec {
namespace capstone2llvmir {

void Capstone2LlvmIrTranslatorArm::initializeRegNameMap()
{
	std::map<uint32_t, std::string> r2n =
	{
			{ARM_REG_CPSR_N, "cpsr_n"},
			{ARM_REG_CPSR_Z, "cpsr_z"},
			{ARM_REG_CPSR_C, "cpsr_c"},
			{ARM_REG_CPSR_V, "cpsr_v"},
	};

	_reg2name = std::move(r2n);
}

void Capstone2LlvmIrTranslatorArm::initializeRegTypeMap()
{
	auto* i1 = llvm::IntegerType::getInt1Ty(_module->getContext());
	auto* defTy = getDefaultType();

	std::map<uint32_t, llvm::Type*> r2t =
	{
			// General purpose registers.
			//
			{ARM_REG_R0, defTy},
			{ARM_REG_R1, defTy},
			{ARM_REG_R2, defTy},
			{ARM_REG_R3, defTy},
			{ARM_REG_R4, defTy},
			{ARM_REG_R5, defTy},
			{ARM_REG_R6, defTy},
			{ARM_REG_R7, defTy},
			{ARM_REG_R8, defTy},
			{ARM_REG_R9, defTy},
			{ARM_REG_R10, defTy},
			{ARM_REG_R11, defTy},
			{ARM_REG_R12, defTy},

			// Special registers.
			//
			{ARM_REG_SP, defTy},
			{ARM_REG_LR, defTy},
			{ARM_REG_PC, defTy},

			// CPSR flags.
			//
			{ARM_REG_CPSR_N, i1},
			{ARM_REG_CPSR_Z, i1},
			{ARM_REG_CPSR_C, i1},
			{ARM_REG_CPSR_V, i1},
	};

	_reg2type = std::move(r2t);
}

void Capstone2LlvmIrTranslatorArm::initializeArchSpecific()
{
	// Nothing.
}

std::map<
	std::size_t,
	void (Capstone2LlvmIrTranslatorArm::*)(cs_insn* i, cs_arm*, llvm::IRBuilder<>&)>
Capstone2LlvmIrTranslatorArm::_i2fm =
{
		{ARM_INS_INVALID, nullptr},

		{ARM_INS_ADC, &Capstone2LlvmIrTranslatorArm::translateAdc},
		{ARM_INS_ADD, &Capstone2LlvmIrTranslatorArm::translateAdd},
		{ARM_INS_ADR, nullptr},
		{ARM_INS_AESD, nullptr},
		{ARM_INS_AESE, nullptr},
		{ARM_INS_AESIMC, nullptr},
		{ARM_INS_AESMC, nullptr},
		{ARM_INS_AND, &Capstone2LlvmIrTranslatorArm::translateAnd},
		{ARM_INS_BFC, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm3Args},
		{ARM_INS_BFI, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm4Args},
		{ARM_INS_BIC, &Capstone2LlvmIrTranslatorArm::translateAnd},
		{ARM_INS_BKPT, nullptr},
		{ARM_INS_BL, &Capstone2LlvmIrTranslatorArm::translateBl},
		{ARM_INS_BLX, &Capstone2LlvmIrTranslatorArm::translateBl},
		{ARM_INS_BX, &Capstone2LlvmIrTranslatorArm::translateB},
		{ARM_INS_BXJ, nullptr},
		{ARM_INS_B, &Capstone2LlvmIrTranslatorArm::translateB},
		{ARM_INS_CDP, nullptr},
		{ARM_INS_CDP2, nullptr},
		{ARM_INS_CLREX, nullptr},
		{ARM_INS_CLZ, &Capstone2LlvmIrTranslatorArm::translateClz},
		{ARM_INS_CMN, &Capstone2LlvmIrTranslatorArm::translateAdd},
		{ARM_INS_CMP, &Capstone2LlvmIrTranslatorArm::translateSub},
		{ARM_INS_CPS, nullptr},
		{ARM_INS_CRC32B, nullptr},
		{ARM_INS_CRC32CB, nullptr},
		{ARM_INS_CRC32CH, nullptr},
		{ARM_INS_CRC32CW, nullptr},
		{ARM_INS_CRC32H, nullptr},
		{ARM_INS_CRC32W, nullptr},
		{ARM_INS_DBG, nullptr},
		{ARM_INS_DMB, nullptr},
		{ARM_INS_DSB, nullptr},
		{ARM_INS_EOR, &Capstone2LlvmIrTranslatorArm::translateEor},
		{ARM_INS_ERET, nullptr},
		{ARM_INS_VMOV, nullptr},
		{ARM_INS_FLDMDBX, nullptr},
		{ARM_INS_FLDMIAX, nullptr},
		{ARM_INS_VMRS, nullptr},
		{ARM_INS_FSTMDBX, nullptr},
		{ARM_INS_FSTMIAX, nullptr},
		{ARM_INS_HINT, nullptr},
		{ARM_INS_HLT, nullptr},
		{ARM_INS_HVC, nullptr},
		{ARM_INS_ISB, nullptr},
		{ARM_INS_LDA, nullptr},
		{ARM_INS_LDAB, nullptr},
		{ARM_INS_LDAEX, nullptr},
		{ARM_INS_LDAEXB, nullptr},
		{ARM_INS_LDAEXD, nullptr},
		{ARM_INS_LDAEXH, nullptr},
		{ARM_INS_LDAH, nullptr},
		{ARM_INS_LDC2L, nullptr},
		{ARM_INS_LDC2, nullptr},
		{ARM_INS_LDCL, nullptr},
		{ARM_INS_LDC, nullptr},
		{ARM_INS_LDMDA, &Capstone2LlvmIrTranslatorArm::translateLdmStm},
		{ARM_INS_LDMDB, &Capstone2LlvmIrTranslatorArm::translateLdmStm},
		{ARM_INS_LDM, &Capstone2LlvmIrTranslatorArm::translateLdmStm},
		{ARM_INS_LDMIB, &Capstone2LlvmIrTranslatorArm::translateLdmStm},
		{ARM_INS_LDRBT, &Capstone2LlvmIrTranslatorArm::translateLdr},
		{ARM_INS_LDRB, &Capstone2LlvmIrTranslatorArm::translateLdr},
		{ARM_INS_LDRD, &Capstone2LlvmIrTranslatorArm::translateLdrd},
		{ARM_INS_LDREX, &Capstone2LlvmIrTranslatorArm::translateLdr},
		{ARM_INS_LDREXB, &Capstone2LlvmIrTranslatorArm::translateLdr},
		{ARM_INS_LDREXD, &Capstone2LlvmIrTranslatorArm::translateLdrd},
		{ARM_INS_LDREXH, &Capstone2LlvmIrTranslatorArm::translateLdr},
		{ARM_INS_LDRH, &Capstone2LlvmIrTranslatorArm::translateLdr},
		{ARM_INS_LDRHT, &Capstone2LlvmIrTranslatorArm::translateLdr},
		{ARM_INS_LDRSB, &Capstone2LlvmIrTranslatorArm::translateLdr},
		{ARM_INS_LDRSBT, &Capstone2LlvmIrTranslatorArm::translateLdr},
		{ARM_INS_LDRSH, &Capstone2LlvmIrTranslatorArm::translateLdr},
		{ARM_INS_LDRSHT, &Capstone2LlvmIrTranslatorArm::translateLdr},
		{ARM_INS_LDRT, &Capstone2LlvmIrTranslatorArm::translateLdr},
		{ARM_INS_LDR, &Capstone2LlvmIrTranslatorArm::translateLdr},
		{ARM_INS_MCR, nullptr},
		{ARM_INS_MCR2, nullptr},
		{ARM_INS_MCRR, nullptr},
		{ARM_INS_MCRR2, nullptr},
		{ARM_INS_MLA, &Capstone2LlvmIrTranslatorArm::translateMla},
		{ARM_INS_MLS, &Capstone2LlvmIrTranslatorArm::translateMls},
		{ARM_INS_MOV, &Capstone2LlvmIrTranslatorArm::translateMov},
		{ARM_INS_MOVT, &Capstone2LlvmIrTranslatorArm::translateMovt},
		{ARM_INS_MOVW, &Capstone2LlvmIrTranslatorArm::translateMovw},
		{ARM_INS_MRC, nullptr},
		{ARM_INS_MRC2, nullptr},
		{ARM_INS_MRRC, nullptr},
		{ARM_INS_MRRC2, nullptr},
		{ARM_INS_MRS, nullptr},
		{ARM_INS_MSR, nullptr},
		{ARM_INS_MUL, &Capstone2LlvmIrTranslatorArm::translateMul},
		{ARM_INS_MVN, &Capstone2LlvmIrTranslatorArm::translateMov},
		{ARM_INS_ORR, &Capstone2LlvmIrTranslatorArm::translateOrr},
		{ARM_INS_PKHBT, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_PKHTB, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_PLDW, nullptr},
		{ARM_INS_PLD, nullptr},
		{ARM_INS_PLI, nullptr},
		{ARM_INS_QADD, nullptr},
		{ARM_INS_QADD16, nullptr},
		{ARM_INS_QADD8, nullptr},
		{ARM_INS_QASX, nullptr},
		{ARM_INS_QDADD, nullptr},
		{ARM_INS_QDSUB, nullptr},
		{ARM_INS_QSAX, nullptr},
		{ARM_INS_QSUB, nullptr},
		{ARM_INS_QSUB16, nullptr},
		{ARM_INS_QSUB8, nullptr},
		{ARM_INS_RBIT, &Capstone2LlvmIrTranslatorArm::translateBinaryPseudoAsm},
		{ARM_INS_REV, &Capstone2LlvmIrTranslatorArm::translateRev},
		{ARM_INS_REV16, &Capstone2LlvmIrTranslatorArm::translateBinaryPseudoAsm},
		{ARM_INS_REVSH, &Capstone2LlvmIrTranslatorArm::translateBinaryPseudoAsm},
		{ARM_INS_RFEDA, nullptr},
		{ARM_INS_RFEDB, nullptr},
		{ARM_INS_RFEIA, nullptr},
		{ARM_INS_RFEIB, nullptr},
		{ARM_INS_RSB, &Capstone2LlvmIrTranslatorArm::translateSub},
		{ARM_INS_RSC, &Capstone2LlvmIrTranslatorArm::translateSbc},
		{ARM_INS_SADD16, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SADD8, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SASX, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SBC, &Capstone2LlvmIrTranslatorArm::translateSbc},
		{ARM_INS_SBFX, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm},
		{ARM_INS_SDIV, nullptr},
		{ARM_INS_SEL, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SETEND, nullptr},
		{ARM_INS_SHA1C, nullptr},
		{ARM_INS_SHA1H, nullptr},
		{ARM_INS_SHA1M, nullptr},
		{ARM_INS_SHA1P, nullptr},
		{ARM_INS_SHA1SU0, nullptr},
		{ARM_INS_SHA1SU1, nullptr},
		{ARM_INS_SHA256H, nullptr},
		{ARM_INS_SHA256H2, nullptr},
		{ARM_INS_SHA256SU0, nullptr},
		{ARM_INS_SHA256SU1, nullptr},
		{ARM_INS_SHADD16, nullptr},
		{ARM_INS_SHADD8, nullptr},
		{ARM_INS_SHASX, nullptr},
		{ARM_INS_SHSAX, nullptr},
		{ARM_INS_SHSUB16, nullptr},
		{ARM_INS_SHSUB8, nullptr},
		{ARM_INS_SMC, nullptr},
		{ARM_INS_SMLABB, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm},
		{ARM_INS_SMLABT, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm},
		{ARM_INS_SMLAD, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm},
		{ARM_INS_SMLADX, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm},
		{ARM_INS_SMLAL, &Capstone2LlvmIrTranslatorArm::translateUmlal},
		{ARM_INS_SMLALBB, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm4Args2Dsts},
		{ARM_INS_SMLALBT, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm4Args2Dsts},
		{ARM_INS_SMLALD, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm4Args2Dsts},
		{ARM_INS_SMLALDX, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm4Args2Dsts},
		{ARM_INS_SMLALTB, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm4Args2Dsts},
		{ARM_INS_SMLALTT, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm4Args2Dsts},
		{ARM_INS_SMLATB, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm},
		{ARM_INS_SMLATT, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm},
		{ARM_INS_SMLAWB, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm},
		{ARM_INS_SMLAWT, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm},
		{ARM_INS_SMLSD, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm},
		{ARM_INS_SMLSDX, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm},
		{ARM_INS_SMLSLD, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm4Args2Dsts},
		{ARM_INS_SMLSLDX, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm4Args2Dsts},
		{ARM_INS_SMMLA, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm},
		{ARM_INS_SMMLAR, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm},
		{ARM_INS_SMMLS, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm},
		{ARM_INS_SMMLSR, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm},
		{ARM_INS_SMMUL, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SMMULR, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SMUAD, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SMUADX, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SMULBB, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SMULBT, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SMULL, &Capstone2LlvmIrTranslatorArm::translateUmull},
		{ARM_INS_SMULTB, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SMULTT, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SMULWB, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SMULWT, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SMUSD, nullptr},
		{ARM_INS_SMUSDX, nullptr},
		{ARM_INS_SRSDA, nullptr},
		{ARM_INS_SRSDB, nullptr},
		{ARM_INS_SRSIA, nullptr},
		{ARM_INS_SRSIB, nullptr},
		{ARM_INS_SSAT, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SSAT16, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SSAX, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SSUB16, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SSUB8, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_STC2L, nullptr},
		{ARM_INS_STC2, nullptr},
		{ARM_INS_STCL, nullptr},
		{ARM_INS_STC, nullptr},
		{ARM_INS_STL, nullptr},
		{ARM_INS_STLB, nullptr},
		{ARM_INS_STLEX, nullptr},
		{ARM_INS_STLEXB, nullptr},
		{ARM_INS_STLEXD, nullptr},
		{ARM_INS_STLEXH, nullptr},
		{ARM_INS_STLH, nullptr},
		{ARM_INS_STMDA, &Capstone2LlvmIrTranslatorArm::translateLdmStm},
		{ARM_INS_STMDB, &Capstone2LlvmIrTranslatorArm::translateLdmStm},
		{ARM_INS_STM, &Capstone2LlvmIrTranslatorArm::translateLdmStm},
		{ARM_INS_STMIB, &Capstone2LlvmIrTranslatorArm::translateLdmStm},
		{ARM_INS_STRBT, &Capstone2LlvmIrTranslatorArm::translateStr},
		{ARM_INS_STRB, &Capstone2LlvmIrTranslatorArm::translateStr},
		{ARM_INS_STRD, &Capstone2LlvmIrTranslatorArm::translateStr},
		{ARM_INS_STREX, nullptr},
		{ARM_INS_STREXB, nullptr},
		{ARM_INS_STREXD, nullptr},
		{ARM_INS_STREXH, nullptr},
		{ARM_INS_STRH, &Capstone2LlvmIrTranslatorArm::translateStr},
		{ARM_INS_STRHT, &Capstone2LlvmIrTranslatorArm::translateStr},
		{ARM_INS_STRT, &Capstone2LlvmIrTranslatorArm::translateStr},
		{ARM_INS_STR, &Capstone2LlvmIrTranslatorArm::translateStr},
		{ARM_INS_SUB, &Capstone2LlvmIrTranslatorArm::translateSub},
		{ARM_INS_SVC, &Capstone2LlvmIrTranslatorArm::translateNop},
		{ARM_INS_SWP, nullptr},
		{ARM_INS_SWPB, nullptr},
		{ARM_INS_SXTAB, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SXTAB16, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SXTAH, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_SXTB, &Capstone2LlvmIrTranslatorArm::translateBinaryPseudoAsm},
		{ARM_INS_SXTB16, &Capstone2LlvmIrTranslatorArm::translateBinaryPseudoAsm},
		{ARM_INS_SXTH, &Capstone2LlvmIrTranslatorArm::translateBinaryPseudoAsm},
		{ARM_INS_TEQ, &Capstone2LlvmIrTranslatorArm::translateEor},
		{ARM_INS_TRAP, nullptr},
		{ARM_INS_TST, &Capstone2LlvmIrTranslatorArm::translateAnd},
		{ARM_INS_UADD16, nullptr},
		{ARM_INS_UADD8, nullptr},
		{ARM_INS_UASX, nullptr},
		{ARM_INS_UBFX, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm},
		{ARM_INS_UDF, nullptr},
		{ARM_INS_UDIV, nullptr},
		{ARM_INS_UHADD16, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_UHADD8, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_UHASX, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_UHSAX, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_UHSUB16, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_UHSUB8, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_UMAAL, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm4Args2Dsts},
		{ARM_INS_UMLAL, &Capstone2LlvmIrTranslatorArm::translateUmlal},
		{ARM_INS_UMULL, &Capstone2LlvmIrTranslatorArm::translateUmull},
		{ARM_INS_UQADD16, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_UQADD8, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_UQASX, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_UQSAX, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_UQSUB16, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_UQSUB8, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_USAD8, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_USADA8, &Capstone2LlvmIrTranslatorArm::translateQuaternaryPseudoAsm},
		{ARM_INS_USAT, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_USAT16, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_USAX, nullptr},
		{ARM_INS_USUB16, nullptr},
		{ARM_INS_USUB8, nullptr},
		{ARM_INS_UXTAB, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_UXTAB16, &Capstone2LlvmIrTranslatorArm::translateTernaryPseudoAsm},
		{ARM_INS_UXTAH, &Capstone2LlvmIrTranslatorArm::translateUxtah},
		{ARM_INS_UXTB, &Capstone2LlvmIrTranslatorArm::translateUxtb},
		{ARM_INS_UXTB16, &Capstone2LlvmIrTranslatorArm::translateUxtb16},
		{ARM_INS_UXTH, &Capstone2LlvmIrTranslatorArm::translateUxth},
		{ARM_INS_VABAL, nullptr},
		{ARM_INS_VABA, nullptr},
		{ARM_INS_VABDL, nullptr},
		{ARM_INS_VABD, nullptr},
		{ARM_INS_VABS, nullptr},
		{ARM_INS_VACGE, nullptr},
		{ARM_INS_VACGT, nullptr},
		{ARM_INS_VADD, nullptr},
		{ARM_INS_VADDHN, nullptr},
		{ARM_INS_VADDL, nullptr},
		{ARM_INS_VADDW, nullptr},
		{ARM_INS_VAND, nullptr},
		{ARM_INS_VBIC, nullptr},
		{ARM_INS_VBIF, nullptr},
		{ARM_INS_VBIT, nullptr},
		{ARM_INS_VBSL, nullptr},
		{ARM_INS_VCEQ, nullptr},
		{ARM_INS_VCGE, nullptr},
		{ARM_INS_VCGT, nullptr},
		{ARM_INS_VCLE, nullptr},
		{ARM_INS_VCLS, nullptr},
		{ARM_INS_VCLT, nullptr},
		{ARM_INS_VCLZ, nullptr},
		{ARM_INS_VCMP, nullptr},
		{ARM_INS_VCMPE, nullptr},
		{ARM_INS_VCNT, nullptr},
		{ARM_INS_VCVTA, nullptr},
		{ARM_INS_VCVTB, nullptr},
		{ARM_INS_VCVT, nullptr},
		{ARM_INS_VCVTM, nullptr},
		{ARM_INS_VCVTN, nullptr},
		{ARM_INS_VCVTP, nullptr},
		{ARM_INS_VCVTT, nullptr},
		{ARM_INS_VDIV, nullptr},
		{ARM_INS_VDUP, nullptr},
		{ARM_INS_VEOR, nullptr},
		{ARM_INS_VEXT, nullptr},
		{ARM_INS_VFMA, nullptr},
		{ARM_INS_VFMS, nullptr},
		{ARM_INS_VFNMA, nullptr},
		{ARM_INS_VFNMS, nullptr},
		{ARM_INS_VHADD, nullptr},
		{ARM_INS_VHSUB, nullptr},
		{ARM_INS_VLD1, nullptr},
		{ARM_INS_VLD2, nullptr},
		{ARM_INS_VLD3, nullptr},
		{ARM_INS_VLD4, nullptr},
		{ARM_INS_VLDMDB, nullptr},
		{ARM_INS_VLDMIA, nullptr},
		{ARM_INS_VLDR, nullptr},
		{ARM_INS_VMAXNM, nullptr},
		{ARM_INS_VMAX, nullptr},
		{ARM_INS_VMINNM, nullptr},
		{ARM_INS_VMIN, nullptr},
		{ARM_INS_VMLA, nullptr},
		{ARM_INS_VMLAL, nullptr},
		{ARM_INS_VMLS, nullptr},
		{ARM_INS_VMLSL, nullptr},
		{ARM_INS_VMOVL, nullptr},
		{ARM_INS_VMOVN, nullptr},
		{ARM_INS_VMSR, nullptr},
		{ARM_INS_VMUL, nullptr},
		{ARM_INS_VMULL, nullptr},
		{ARM_INS_VMVN, nullptr},
		{ARM_INS_VNEG, nullptr},
		{ARM_INS_VNMLA, nullptr},
		{ARM_INS_VNMLS, nullptr},
		{ARM_INS_VNMUL, nullptr},
		{ARM_INS_VORN, nullptr},
		{ARM_INS_VORR, nullptr},
		{ARM_INS_VPADAL, nullptr},
		{ARM_INS_VPADDL, nullptr},
		{ARM_INS_VPADD, nullptr},
		{ARM_INS_VPMAX, nullptr},
		{ARM_INS_VPMIN, nullptr},
		{ARM_INS_VQABS, nullptr},
		{ARM_INS_VQADD, nullptr},
		{ARM_INS_VQDMLAL, nullptr},
		{ARM_INS_VQDMLSL, nullptr},
		{ARM_INS_VQDMULH, nullptr},
		{ARM_INS_VQDMULL, nullptr},
		{ARM_INS_VQMOVUN, nullptr},
		{ARM_INS_VQMOVN, nullptr},
		{ARM_INS_VQNEG, nullptr},
		{ARM_INS_VQRDMULH, nullptr},
		{ARM_INS_VQRSHL, nullptr},
		{ARM_INS_VQRSHRN, nullptr},
		{ARM_INS_VQRSHRUN, nullptr},
		{ARM_INS_VQSHL, nullptr},
		{ARM_INS_VQSHLU, nullptr},
		{ARM_INS_VQSHRN, nullptr},
		{ARM_INS_VQSHRUN, nullptr},
		{ARM_INS_VQSUB, nullptr},
		{ARM_INS_VRADDHN, nullptr},
		{ARM_INS_VRECPE, nullptr},
		{ARM_INS_VRECPS, nullptr},
		{ARM_INS_VREV16, nullptr},
		{ARM_INS_VREV32, nullptr},
		{ARM_INS_VREV64, nullptr},
		{ARM_INS_VRHADD, nullptr},
		{ARM_INS_VRINTA, nullptr},
		{ARM_INS_VRINTM, nullptr},
		{ARM_INS_VRINTN, nullptr},
		{ARM_INS_VRINTP, nullptr},
		{ARM_INS_VRINTR, nullptr},
		{ARM_INS_VRINTX, nullptr},
		{ARM_INS_VRINTZ, nullptr},
		{ARM_INS_VRSHL, nullptr},
		{ARM_INS_VRSHRN, nullptr},
		{ARM_INS_VRSHR, nullptr},
		{ARM_INS_VRSQRTE, nullptr},
		{ARM_INS_VRSQRTS, nullptr},
		{ARM_INS_VRSRA, nullptr},
		{ARM_INS_VRSUBHN, nullptr},
		{ARM_INS_VSELEQ, nullptr},
		{ARM_INS_VSELGE, nullptr},
		{ARM_INS_VSELGT, nullptr},
		{ARM_INS_VSELVS, nullptr},
		{ARM_INS_VSHLL, nullptr},
		{ARM_INS_VSHL, nullptr},
		{ARM_INS_VSHRN, nullptr},
		{ARM_INS_VSHR, nullptr},
		{ARM_INS_VSLI, nullptr},
		{ARM_INS_VSQRT, nullptr},
		{ARM_INS_VSRA, nullptr},
		{ARM_INS_VSRI, nullptr},
		{ARM_INS_VST1, nullptr},
		{ARM_INS_VST2, nullptr},
		{ARM_INS_VST3, nullptr},
		{ARM_INS_VST4, nullptr},
		{ARM_INS_VSTMDB, nullptr},
		{ARM_INS_VSTMIA, nullptr},
		{ARM_INS_VSTR, nullptr},
		{ARM_INS_VSUB, nullptr},
		{ARM_INS_VSUBHN, nullptr},
		{ARM_INS_VSUBL, nullptr},
		{ARM_INS_VSUBW, nullptr},
		{ARM_INS_VSWP, nullptr},
		{ARM_INS_VTBL, nullptr},
		{ARM_INS_VTBX, nullptr},
		{ARM_INS_VCVTR, nullptr},
		{ARM_INS_VTRN, nullptr},
		{ARM_INS_VTST, nullptr},
		{ARM_INS_VUZP, nullptr},
		{ARM_INS_VZIP, nullptr},
		{ARM_INS_ADDW, nullptr},
		{ARM_INS_ASR, &Capstone2LlvmIrTranslatorArm::translateShifts},
		{ARM_INS_DCPS1, nullptr},
		{ARM_INS_DCPS2, nullptr},
		{ARM_INS_DCPS3, nullptr},
		{ARM_INS_IT, nullptr},
		{ARM_INS_LSL, &Capstone2LlvmIrTranslatorArm::translateShifts},
		{ARM_INS_LSR, &Capstone2LlvmIrTranslatorArm::translateShifts},
		{ARM_INS_ORN, nullptr},
		{ARM_INS_ROR, &Capstone2LlvmIrTranslatorArm::translateShifts},
		{ARM_INS_RRX, &Capstone2LlvmIrTranslatorArm::translateShifts},
		{ARM_INS_SUBW, nullptr},
		{ARM_INS_TBB, nullptr},
		{ARM_INS_TBH, nullptr},
		{ARM_INS_CBNZ, &Capstone2LlvmIrTranslatorArm::translateCbnz},
		{ARM_INS_CBZ, &Capstone2LlvmIrTranslatorArm::translateCbz},
		{ARM_INS_POP, &Capstone2LlvmIrTranslatorArm::translateLdmStm},
		{ARM_INS_PUSH, &Capstone2LlvmIrTranslatorArm::translateLdmStm},

		// special instructions
		{ARM_INS_NOP, &Capstone2LlvmIrTranslatorArm::translateNop},
		{ARM_INS_YIELD, nullptr},
		{ARM_INS_WFE, nullptr},
		{ARM_INS_WFI, nullptr},
		{ARM_INS_SEV, nullptr},
		{ARM_INS_SEVL, nullptr},
		{ARM_INS_VPUSH, nullptr},
		{ARM_INS_VPOP, nullptr},

		{ARM_INS_ENDING, nullptr},
};

} // namespace capstone2llvmir
} // namespace retdec
