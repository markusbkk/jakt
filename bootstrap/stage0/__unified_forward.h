#pragma once
#include <lib.h>
#ifdef _WIN32
extern "C" __cdecl int SetConsoleOutputCP(unsigned int code_page);
const unsigned int CP_UTF8 = 65001;
#endif
namespace Jakt {
namespace jakt__prelude__iteration {
}
namespace jakt__prelude__prelude {
}
namespace jakt__libc__io {
}
namespace jakt__arguments {
struct ArgsParser;
ErrorOr<String> escape_for_quotes(String const s);

}
namespace utility {
struct Span;
struct FileId;
bool is_ascii_binary(u8 const c);

String join(JaktInternal::Array<String> const strings, String const separator);

template <typename T>
ErrorOr<JaktInternal::Array<T>> add_arrays(JaktInternal::Array<T> const a, JaktInternal::Array<T> const b);

bool is_whitespace(u8 const byte);

bool is_ascii_alpha(u8 const c);

ErrorOr<JaktInternal::Array<String>> prepend_to_each(JaktInternal::Array<String> const strings, String const prefix);

bool is_ascii_digit(u8 const c);

void todo(String const message);

bool is_ascii_alphanumeric(u8 const c);

ErrorOr<String> interpret_escapes(String const s);

ErrorOr<JaktInternal::Array<String>> append_to_each(JaktInternal::Array<String> const strings, String const suffix);

template <typename T>
T* null();

bool is_ascii_octdigit(u8 const c);

bool is_ascii_hexdigit(u8 const c);

[[noreturn]] void panic(String const message);

ErrorOr<String> escape_for_quotes(String const s);

template <typename T>
T* allocate(size_t const count);

}
namespace error {
namespace JaktError_Details {
struct Message;
struct MessageWithHint;
}
struct JaktError;

namespace MessageSeverity_Details {
struct Hint;
struct Error;
}
struct MessageSeverity;

ErrorOr<void> print_error_json(String const file_name, error::JaktError const error);

ErrorOr<JaktInternal::Array<JaktInternal::Tuple<size_t,size_t>>> gather_line_spans(JaktInternal::Array<u8> const file_contents);

ErrorOr<void> display_message_with_span(error::MessageSeverity const severity, String const file_name, JaktInternal::Optional<JaktInternal::Array<u8>> const contents, String const message, utility::Span const span);

ErrorOr<void> print_source_line(error::MessageSeverity const severity, JaktInternal::Array<u8> const file_contents, JaktInternal::Tuple<size_t,size_t> const file_span, utility::Span const error_span, size_t const line_number, size_t const largest_line_number);

ErrorOr<void> display_message_with_span_json(error::MessageSeverity const severity, String const file_name, String const message, utility::Span const span);

ErrorOr<void> print_error(String const file_name, JaktInternal::Optional<JaktInternal::Array<u8>> const file_contents, error::JaktError const error);

}
namespace os {
struct Target;



ErrorOr<JaktInternal::Array<String>> platform_import_names();

}
namespace unknown_path {


}
namespace path {
struct Path;
}
namespace compiler {
class Compiler;
}
namespace lexer {
struct Lexer;
namespace LiteralSuffix_Details {
struct None;
struct UZ;
struct U8;
struct U16;
struct U32;
struct U64;
struct I8;
struct I16;
struct I32;
struct I64;
struct F32;
struct F64;
}
struct LiteralSuffix;

namespace Token_Details {
struct SingleQuotedString;
struct SingleQuotedByteString;
struct QuotedString;
struct Number;
struct Identifier;
struct Semicolon;
struct Colon;
struct ColonColon;
struct LParen;
struct RParen;
struct LCurly;
struct RCurly;
struct LSquare;
struct RSquare;
struct PercentSign;
struct Plus;
struct Minus;
struct Equal;
struct PlusEqual;
struct PlusPlus;
struct MinusEqual;
struct MinusMinus;
struct AsteriskEqual;
struct ForwardSlashEqual;
struct PercentSignEqual;
struct NotEqual;
struct DoubleEqual;
struct GreaterThan;
struct GreaterThanOrEqual;
struct LessThan;
struct LessThanOrEqual;
struct LeftArithmeticShift;
struct LeftShift;
struct LeftShiftEqual;
struct RightShift;
struct RightArithmeticShift;
struct RightShiftEqual;
struct Asterisk;
struct Ampersand;
struct AmpersandEqual;
struct AmpersandAmpersand;
struct Pipe;
struct PipeEqual;
struct PipePipe;
struct Caret;
struct CaretEqual;
struct Dollar;
struct Tilde;
struct ForwardSlash;
struct ExclamationPoint;
struct QuestionMark;
struct QuestionMarkQuestionMark;
struct QuestionMarkQuestionMarkEqual;
struct Comma;
struct Dot;
struct DotDot;
struct Eol;
struct Eof;
struct FatArrow;
struct Arrow;
struct And;
struct Anon;
struct As;
struct Boxed;
struct Break;
struct Catch;
struct Class;
struct Continue;
struct Cpp;
struct Defer;
struct Else;
struct Enum;
struct Extern;
struct False;
struct For;
struct Function;
struct Comptime;
struct If;
struct Import;
struct In;
struct Is;
struct Let;
struct Loop;
struct Match;
struct Mut;
struct Namespace;
struct Not;
struct Or;
struct Override;
struct Private;
struct Public;
struct Raw;
struct Return;
struct Restricted;
struct Struct;
struct This;
struct Throw;
struct Throws;
struct True;
struct Try;
struct Unsafe;
struct Virtual;
struct Weak;
struct While;
struct Yield;
struct Guard;
struct Implements;
struct Requires;
struct Trait;
struct Garbage;
}
struct Token;

namespace LiteralPrefix_Details {
struct None;
struct Hexadecimal;
struct Octal;
struct Binary;
}
struct LiteralPrefix;

}
namespace parser {
struct ParsedGenericParameter;
struct EnumVariantPatternArgument;
struct ParsedBlock;
struct ParsedRecord;
struct ParsedExternalTraitImplementation;
struct ParsedFunction;
struct ParsedExternImport;
struct ParsedModuleImport;
struct ParsedVariable;
struct ParsedNameWithGenericParameters;
struct SumEnumVariant;
struct ParsedMatchCase;
struct ParsedTrait;
struct Parser;
struct ParsedCall;
struct ParsedNamespace;
struct ParsedName;
struct ParsedVarDecl;
struct ParsedMethod;
struct ParsedField;
struct ParsedParameter;
struct ValueEnumVariant;
struct VisibilityRestriction;
namespace IncludeAction_Details {
struct Define;
struct Undefine;
}
struct IncludeAction;

namespace ParsedExpression_Details {
struct Boolean;
struct NumericConstant;
struct QuotedString;
struct SingleQuotedString;
struct SingleQuotedByteString;
struct Call;
struct MethodCall;
struct IndexedTuple;
struct IndexedStruct;
struct Var;
struct IndexedExpression;
struct UnaryOp;
struct BinaryOp;
struct Operator;
struct OptionalSome;
struct OptionalNone;
struct JaktArray;
struct JaktDictionary;
struct Set;
struct JaktTuple;
struct Range;
struct ForcedUnwrap;
struct Match;
struct EnumVariantArg;
struct NamespacedVar;
struct Function;
struct Try;
struct TryBlock;
struct Garbage;
}
struct ParsedExpression;

namespace ImportList_Details {
struct List;
struct All;
}
struct ImportList;

namespace ParsedCapture_Details {
struct ByValue;
struct ByReference;
struct ByMutableReference;
}
struct ParsedCapture;

namespace BinaryOperator_Details {
struct Add;
struct Subtract;
struct Multiply;
struct Divide;
struct Modulo;
struct LessThan;
struct LessThanOrEqual;
struct GreaterThan;
struct GreaterThanOrEqual;
struct Equal;
struct NotEqual;
struct BitwiseAnd;
struct BitwiseXor;
struct BitwiseOr;
struct BitwiseLeftShift;
struct BitwiseRightShift;
struct ArithmeticLeftShift;
struct ArithmeticRightShift;
struct LogicalAnd;
struct LogicalOr;
struct NoneCoalescing;
struct Assign;
struct BitwiseAndAssign;
struct BitwiseOrAssign;
struct BitwiseXorAssign;
struct BitwiseLeftShiftAssign;
struct BitwiseRightShiftAssign;
struct AddAssign;
struct SubtractAssign;
struct MultiplyAssign;
struct ModuloAssign;
struct DivideAssign;
struct NoneCoalescingAssign;
struct Garbage;
}
struct BinaryOperator;

namespace FunctionType_Details {
struct Normal;
struct ImplicitConstructor;
struct ImplicitEnumConstructor;
struct ExternalClassConstructor;
struct Expression;
struct Closure;
}
struct FunctionType;

namespace ParsedStatement_Details {
struct Expression;
struct Defer;
struct UnsafeBlock;
struct DestructuringAssignment;
struct VarDecl;
struct If;
struct Block;
struct Loop;
struct While;
struct For;
struct Break;
struct Continue;
struct Return;
struct Throw;
struct Yield;
struct InlineCpp;
struct Guard;
struct Garbage;
}
struct ParsedStatement;

namespace ParsedMatchPattern_Details {
struct EnumVariant;
struct Expression;
struct CatchAll;
struct Invalid;
}
struct ParsedMatchPattern;

namespace FunctionLinkage_Details {
struct Internal;
struct External;
}
struct FunctionLinkage;

namespace ImportName_Details {
struct Literal;
struct Comptime;
}
struct ImportName;

namespace ParsedMatchBody_Details {
struct Expression;
struct Block;
}
struct ParsedMatchBody;

namespace DefinitionLinkage_Details {
struct Internal;
struct External;
}
struct DefinitionLinkage;

namespace RecordType_Details {
struct Struct;
struct Class;
struct ValueEnum;
struct SumEnum;
struct Garbage;
}
struct RecordType;

namespace Visibility_Details {
struct Public;
struct Private;
struct Restricted;
}
struct Visibility;

namespace ParsedType_Details {
struct Name;
struct NamespacedName;
struct GenericType;
struct JaktArray;
struct Dictionary;
struct JaktTuple;
struct Set;
struct Optional;
struct Reference;
struct MutableReference;
struct RawPtr;
struct WeakPtr;
struct Function;
struct Empty;
}
struct ParsedType;

namespace TypeCast_Details {
struct Fallible;
struct Infallible;
}
struct TypeCast;

namespace NumericConstant_Details {
struct I8;
struct I16;
struct I32;
struct I64;
struct U8;
struct U16;
struct U32;
struct U64;
struct USize;
struct F32;
struct F64;
struct UnknownSigned;
struct UnknownUnsigned;
}
struct NumericConstant;

namespace UnaryOperator_Details {
struct PreIncrement;
struct PostIncrement;
struct PreDecrement;
struct PostDecrement;
struct Negate;
struct Dereference;
struct RawAddress;
struct Reference;
struct MutableReference;
struct LogicalNot;
struct BitwiseNot;
struct TypeCast;
struct Is;
struct IsEnumVariant;
}
struct UnaryOperator;

ErrorOr<utility::Span> merge_spans(utility::Span const start, utility::Span const end);

f32 f64_to_f32(f64 const number);

template <typename T>
T u64_to_float(u64 const number);

}
namespace types {
class FunctionGenerics;
struct GenericInferences;
struct CheckedStruct;
struct CheckedVariable;
class CheckedProgram;
struct Value;
struct VarId;
struct CheckedParameter;
struct CheckedCall;
struct CheckedVarDecl;
struct CheckedNamespace;
struct CheckedGenericParameter;
struct CheckedBlock;
struct TraitId;
struct FunctionId;
class Module;
class CheckedTrait;
class CheckedFunction;
struct EnumId;
struct StructId;
struct ScopeId;
struct LoadedModule;
struct CheckedEnum;
struct FunctionGenericParameter;
struct ResolvedNamespace;
class Scope;
struct TypeId;
struct FieldRecord;
struct ModuleId;
struct CheckedEnumVariantBinding;
struct CheckedField;
namespace SafetyMode_Details {
struct Safe;
struct Unsafe;
}
struct SafetyMode;

namespace FunctionGenericParameterKind_Details {
struct InferenceGuide;
struct Parameter;
}
struct FunctionGenericParameterKind;

namespace Type_Details {
struct Void;
struct Bool;
struct U8;
struct U16;
struct U32;
struct U64;
struct I8;
struct I16;
struct I32;
struct I64;
struct F32;
struct F64;
struct Usize;
struct JaktString;
struct CChar;
struct CInt;
struct Unknown;
struct Never;
struct TypeVariable;
struct GenericInstance;
struct GenericEnumInstance;
struct GenericTraitInstance;
struct GenericResolvedType;
struct Struct;
struct Enum;
struct RawPtr;
struct Trait;
struct Reference;
struct MutableReference;
struct Function;
}
struct Type;

namespace CheckedMatchBody_Details {
struct Expression;
struct Block;
}
struct CheckedMatchBody;

namespace CheckedStatement_Details {
struct Expression;
struct Defer;
struct DestructuringAssignment;
struct VarDecl;
struct If;
struct Block;
struct Loop;
struct While;
struct Return;
struct Break;
struct Continue;
struct Throw;
struct Yield;
struct InlineCpp;
struct Garbage;
}
struct CheckedStatement;

namespace CheckedEnumVariant_Details {
struct Untyped;
struct Typed;
struct WithValue;
struct StructLike;
}
struct CheckedEnumVariant;

namespace CheckedMatchCase_Details {
struct EnumVariant;
struct Expression;
struct CatchAll;
}
struct CheckedMatchCase;

namespace CheckedTypeCast_Details {
struct Fallible;
struct Infallible;
}
struct CheckedTypeCast;

namespace NumberConstant_Details {
struct Signed;
struct Unsigned;
struct Floating;
}
struct NumberConstant;

namespace CheckedUnaryOperator_Details {
struct PreIncrement;
struct PostIncrement;
struct PreDecrement;
struct PostDecrement;
struct Negate;
struct Dereference;
struct RawAddress;
struct Reference;
struct MutableReference;
struct LogicalNot;
struct BitwiseNot;
struct TypeCast;
struct Is;
struct IsEnumVariant;
}
struct CheckedUnaryOperator;

namespace BlockControlFlow_Details {
struct AlwaysReturns;
struct AlwaysTransfersControl;
struct NeverReturns;
struct MayReturn;
struct PartialAlwaysReturns;
struct PartialAlwaysTransfersControl;
struct PartialNeverReturns;
}
struct BlockControlFlow;

namespace CheckedCapture_Details {
struct ByValue;
struct ByReference;
struct ByMutableReference;
}
struct CheckedCapture;

namespace StructOrEnumId_Details {
struct Struct;
struct Enum;
}
struct StructOrEnumId;

namespace MaybeResolvedScope_Details {
struct Resolved;
struct Unresolved;
}
struct MaybeResolvedScope;

namespace CheckedExpression_Details {
struct Boolean;
struct NumericConstant;
struct QuotedString;
struct ByteConstant;
struct CharacterConstant;
struct UnaryOp;
struct BinaryOp;
struct JaktTuple;
struct Range;
struct JaktArray;
struct JaktSet;
struct JaktDictionary;
struct IndexedExpression;
struct IndexedDictionary;
struct IndexedTuple;
struct IndexedStruct;
struct IndexedCommonEnumMember;
struct Match;
struct EnumVariantArg;
struct Call;
struct MethodCall;
struct NamespacedVar;
struct Var;
struct OptionalNone;
struct OptionalSome;
struct ForcedUnwrap;
struct Block;
struct Function;
struct Try;
struct TryBlock;
struct Garbage;
}
struct CheckedExpression;

namespace ValueImpl_Details {
struct Void;
struct Bool;
struct U8;
struct U16;
struct U32;
struct U64;
struct I8;
struct I16;
struct I32;
struct I64;
struct F32;
struct F64;
struct USize;
struct JaktString;
struct CChar;
struct CInt;
struct Struct;
struct Class;
struct Enum;
struct JaktArray;
struct JaktDictionary;
struct JaktSet;
struct RawPtr;
struct OptionalSome;
struct OptionalNone;
struct JaktTuple;
struct Function;
}
struct ValueImpl;

namespace CheckedVisibility_Details {
struct Public;
struct Private;
struct Restricted;
}
struct CheckedVisibility;

namespace CheckedNumericConstant_Details {
struct I8;
struct I16;
struct I32;
struct I64;
struct U8;
struct U16;
struct U32;
struct U64;
struct USize;
struct F32;
struct F64;
}
struct CheckedNumericConstant;

namespace BuiltinType_Details {
struct Void;
struct Bool;
struct U8;
struct U16;
struct U32;
struct U64;
struct I8;
struct I16;
struct I32;
struct I64;
struct F32;
struct F64;
struct Usize;
struct JaktString;
struct CChar;
struct CInt;
struct Unknown;
struct Never;
}
struct BuiltinType;

types::TypeId builtin(types::BuiltinType const builtin);

types::TypeId void_type_id();

types::TypeId unknown_type_id();

types::TypeId never_type_id();

}
namespace interpreter {
class Interpreter;
class InterpreterScope;
namespace StatementResult_Details {
struct Return;
struct Throw;
struct Yield;
struct Continue;
struct Break;
struct JustValue;
}
struct StatementResult;

namespace ExecutionResult_Details {
struct Return;
struct Throw;
}
struct ExecutionResult;

namespace Deferred_Details {
struct Expression;
struct Statement;
}
struct Deferred;

enum class InterpretError: i32;
ErrorOr<types::Value> cast_value_to_type(types::Value const this_value, types::TypeId const type_id, NonnullRefPtr<interpreter::Interpreter> const interpreter, bool const saturating);

ErrorOr<NonnullRefPtr<types::CheckedExpression>> value_to_checked_expression(types::Value const this_value, NonnullRefPtr<interpreter::Interpreter> interpreter);

}
namespace typechecker {
struct AlreadyImplementedFor;
struct Typechecker;
struct TraitImplCheck;
namespace FunctionMatchResult_Details {
struct MatchSuccess;
struct MatchError;
}
struct FunctionMatchResult;

}
namespace codegen {
struct LineSpan;
struct CodegenDebugInfo;
struct CodeGenerator;
struct ControlFlowState;
namespace AllowedControlExits_Details {
struct Nothing;
struct JustReturn;
struct AtLoop;
}
struct AllowedControlExits;

bool are_loop_exits_allowed(codegen::AllowedControlExits const allowed_control_exits);

bool is_return_allowed(codegen::AllowedControlExits const allowed_control_exits);

}
namespace formatter {
struct FormattedToken;
struct ReflowState;
struct Formatter;
struct Stage0;
namespace BreakablePoint_Details {
struct Paren;
struct Curly;
struct Square;
struct Logical;
}
struct BreakablePoint;

namespace State_Details {
struct Toplevel;
struct Import;
struct ImportList;
struct EntityDeclaration;
struct ParameterList;
struct RestrictionList;
struct EntityDefinition;
struct StatementContext;
struct MatchPattern;
struct VariableDeclaration;
struct GenericCallTypeParams;
struct TypeContext;
struct FunctionTypeContext;
}
struct State;

namespace Entity_Details {
struct Struct;
struct Enum;
struct Namespace;
struct Function;
}
struct Entity;

namespace ExpressionMode_Details {
struct OutsideExpression;
struct BeforeExpressions;
struct AtExpressionStart;
struct InExpression;
}
struct ExpressionMode;

template <typename T>
JaktInternal::Optional<T> collapse(JaktInternal::Optional<JaktInternal::Optional<T>> const x);

template <typename T>
ErrorOr<JaktInternal::Array<T>> concat(JaktInternal::Array<T> const xs, T const y);

void bubble_sort(JaktInternal::Array<String> values);

template <typename T>
ErrorOr<JaktInternal::Array<T>> init(JaktInternal::Array<T> const xs);

}
namespace jakt__libc__io {
}
namespace repl {
struct Editor;
struct REPL;
namespace LineResult_Details {
struct Line;
struct Eof;
}
struct LineResult;

String serialize_unary_operation(types::CheckedUnaryOperator const op, String const expr);

ErrorOr<String> serialize_ast_node(NonnullRefPtr<types::CheckedExpression> const node);

}
namespace ide {
struct JaktSymbol;
namespace Mutability_Details {
struct DoesNotApply;
struct Immutable;
struct Mutable;
}
struct Mutability;

namespace Usage_Details {
struct Variable;
struct Call;
struct Typename;
struct NameSet;
struct EnumVariant;
}
struct Usage;

namespace VarType_Details {
struct Variable;
struct Field;
}
struct VarType;

namespace VarVisibility_Details {
struct DoesNotApply;
struct Public;
struct Private;
struct Restricted;
}
struct VarVisibility;

ErrorOr<ide::JaktSymbol> record_to_symbol(parser::ParsedRecord const record);

ErrorOr<JaktInternal::Optional<String>> find_typename_in_program(NonnullRefPtr<types::CheckedProgram> const program, utility::Span const span);

ErrorOr<JaktInternal::Array<String>> completions_for_type_id(NonnullRefPtr<types::CheckedProgram> const program, types::TypeId const type_id);

ErrorOr<ide::Usage> get_enum_variant_usage_from_type_id_and_name(NonnullRefPtr<types::CheckedProgram> const program, types::TypeId const type_id, String const name);

ErrorOr<String> get_enum_variant_signature_from_type_id_and_name(NonnullRefPtr<types::CheckedProgram> const program, types::TypeId const type_id, String const name);

ErrorOr<String> get_type_signature(NonnullRefPtr<types::CheckedProgram> const program, types::TypeId const type_id);

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_scope(NonnullRefPtr<types::CheckedProgram> const program, NonnullRefPtr<types::Scope> const scope, utility::Span const span);

ErrorOr<String> get_constructor_signature(NonnullRefPtr<types::CheckedProgram> const program, types::FunctionId const function_id);

ErrorOr<JaktInternal::Array<String>> find_dot_completions(NonnullRefPtr<types::CheckedProgram> const program, utility::Span const span);

ErrorOr<utility::Span> find_definition_in_program(NonnullRefPtr<types::CheckedProgram> const program, utility::Span const span);

ErrorOr<String> get_var_signature(NonnullRefPtr<types::CheckedProgram> const program, String const name, types::TypeId const var_type_id, ide::Mutability const mutability, ide::VarType const var_type, ide::VarVisibility const visibility, JaktInternal::Optional<types::TypeId> const struct_type_id);

ErrorOr<JaktInternal::Array<JaktInternal::Tuple<JaktInternal::Optional<String>,types::TypeId>>> enum_variant_fields(NonnullRefPtr<types::CheckedProgram> const program, types::CheckedEnumVariant const checked_enum_variant);

ErrorOr<utility::Span> find_type_definition_in_program(NonnullRefPtr<types::CheckedProgram> const program, utility::Span const span);

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_expression(NonnullRefPtr<types::CheckedProgram> const program, NonnullRefPtr<types::CheckedExpression> const expr, utility::Span const span);

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_block(NonnullRefPtr<types::CheckedProgram> const program, types::CheckedBlock const block, utility::Span const span);

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_program(NonnullRefPtr<types::CheckedProgram> const program, utility::Span const span);

ErrorOr<JaktInternal::Array<String>> find_function_completions_in_scope(NonnullRefPtr<types::Scope> const scope, NonnullRefPtr<types::CheckedProgram> const program);

ErrorOr<JaktInternal::Array<ide::JaktSymbol>> find_symbols_in_namespace(parser::ParsedNamespace const namespace_);

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_function(NonnullRefPtr<types::CheckedProgram> const program, NonnullRefPtr<types::CheckedFunction> const checked_function, utility::Span const span);

ErrorOr<utility::Span> find_type_definition_for_type_id(NonnullRefPtr<types::CheckedProgram> const program, types::TypeId const type_id, utility::Span const span);

ErrorOr<String> get_enum_variant_signature(NonnullRefPtr<types::CheckedProgram> const program, String const name, types::TypeId const type_id, JaktInternal::Array<JaktInternal::Tuple<JaktInternal::Optional<String>,types::TypeId>> const variants, JaktInternal::Optional<types::NumberConstant> const number_constant);

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_enum(NonnullRefPtr<types::CheckedProgram> const program, types::CheckedEnum const checked_enum, utility::Span const span);

ErrorOr<ide::JaktSymbol> function_to_symbol(parser::ParsedFunction const function_, String const kind);

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_statement(NonnullRefPtr<types::CheckedProgram> const program, NonnullRefPtr<types::CheckedStatement> const statement, utility::Span const span);

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_struct(NonnullRefPtr<types::CheckedProgram> const program, types::CheckedStruct const checked_struct, utility::Span const span);

ErrorOr<String> get_function_signature(NonnullRefPtr<types::CheckedProgram> const program, types::FunctionId const function_id);

}
namespace unknown_process {
struct Process;
struct ExitPollResult;
ErrorOr<unknown_process::Process> start_background_process(JaktInternal::Array<String> const args);

ErrorOr<JaktInternal::Tuple<JaktInternal::Optional<size_t>,unknown_process::ExitPollResult>> wait_for_some_set_of_processes_that_at_least_includes(JaktInternal::Dictionary<size_t,unknown_process::Process> const& processes);

ErrorOr<unknown_process::ExitPollResult> wait_for_process(unknown_process::Process const& process);

ErrorOr<void> forcefully_kill_process(unknown_process::Process const& process);

ErrorOr<JaktInternal::Optional<unknown_process::ExitPollResult>> poll_process_exit(unknown_process::Process const& process);

}
namespace build {
struct Builder;
struct ParallelExecutionPool;
}
namespace unknown_fs {
ErrorOr<void> make_directory(String const path);

}
namespace unknown_compiler {
ErrorOr<JaktInternal::Array<String>> run_compiler(String const cxx_compiler_path, String const cpp_filename, String const output_filename, String const runtime_path, JaktInternal::Array<String> const extra_include_paths, JaktInternal::Array<String> const extra_lib_paths, JaktInternal::Array<String> const extra_link_libs, bool const optimize, JaktInternal::Array<String> const extra_compiler_flags);

}
struct FormatRange;
ErrorOr<void> write_to_file(String const data, String const output_filename);


String help();

ErrorOr<JaktInternal::Optional<FormatRange>> parse_format_range(String const range, size_t const input_file_length);

ErrorOr<String> indent(size_t const level);

template <typename T>
ErrorOr<T> value_or_throw(JaktInternal::Optional<T> const maybe);

String usage();


} // namespace Jakt
