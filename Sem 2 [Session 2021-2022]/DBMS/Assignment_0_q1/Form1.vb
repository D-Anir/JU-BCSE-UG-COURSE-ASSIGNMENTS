Public Class Form1
    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Me.Text = "Arithmatic Form                      Current Date: " + DateTime.Now.ToString("MM/dd/yyyy")
    End Sub

    Private Sub addBtn_Click(sender As Object, e As EventArgs) Handles addBtn.Click
        Dim num1, num2 As Double
        Dim sum As Double

        num1 = Val(numberText2.Text)
        num2 = Val(numberText1.Text)

        sum = num1 + num2

        resultText.Text = sum

    End Sub

    Private Sub subBtn_Click(sender As Object, e As EventArgs) Handles subBtn.Click
        Dim num1, num2 As Double
        Dim diff As Integer

        num1 = Val(numberText2.Text)
        num2 = Val(numberText1.Text)

        diff = num1 - num2

        resultText.Text = Math.Abs(diff)

    End Sub

    Private Sub clearBtn_Click(sender As Object, e As EventArgs) Handles clearBtn.Click
        numberText1.Text = ""
        numberText2.Text = ""
        resultText.Text = ""
    End Sub

End Class
