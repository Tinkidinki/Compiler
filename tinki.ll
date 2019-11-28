; ModuleID = 'Tinki Compiler'
source_filename = "Tinki Compiler"

@b = common global i32 0, align 4
@0 = private unnamed_addr constant [6 x i8] c"Hello\00", align 1

declare i32 @printf(i8* %0, ...)

define void @main() {
entry:
  %printfcall = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @0, i32 0, i32 0))
}
