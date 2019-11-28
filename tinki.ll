; ModuleID = 'Tinki Compiler'
source_filename = "Tinki Compiler"

@0 = private unnamed_addr constant [3 x i8] c"if\00", align 1
@1 = private unnamed_addr constant [9 x i8] c"if again\00", align 1
@2 = private unnamed_addr constant [5 x i8] c"else\00", align 1
@3 = private unnamed_addr constant [7 x i8] c"always\00", align 1

declare i32 @printf(i8* %0, ...)

define i32 @main() {
entry:
  %x = alloca i32
  %y = alloca i32
  store i32 0, i32* %x
  store i32 7, i32* %y
  %0 = load i32, i32* %x
  %1 = load i32, i32* %y
  %gtcompare = icmp sgt i32 %0, %1
  br i1 %gtcompare, label %if, label %else

if:                                               ; preds = %entry
  %printfcall = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @0, i32 0, i32 0))
  %printfcall1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([9 x i8], [9 x i8]* @1, i32 0, i32 0))
  br label %merge

else:                                             ; preds = %entry
  %printfcall2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @2, i32 0, i32 0))
  br label %merge

merge:                                            ; preds = %else, %if
  %printfcall3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @3, i32 0, i32 0))
  ret i32 0
}
