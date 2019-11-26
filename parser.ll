; ModuleID = 'Tinki Compiler'
source_filename = "Tinki Compiler"

@0 = private unnamed_addr constant [3 x i8] c"%d\00", align 1

declare i32 @printf(i8* %0, ...)

define i32 @main() {
entry:
  %printfcall = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @0, i32 0, i32 0), i1 true)
  ret i32 0
}