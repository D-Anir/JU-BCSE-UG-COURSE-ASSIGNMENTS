<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()>
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.resultText = New System.Windows.Forms.TextBox()
        Me.GroupBox2 = New System.Windows.Forms.GroupBox()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.numberText1 = New System.Windows.Forms.TextBox()
        Me.numberText2 = New System.Windows.Forms.TextBox()
        Me.addBtn = New System.Windows.Forms.Button()
        Me.subBtn = New System.Windows.Forms.Button()
        Me.clearBtn = New System.Windows.Forms.Button()
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.SuspendLayout()
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.Label1)
        Me.GroupBox1.Controls.Add(Me.resultText)
        Me.GroupBox1.Location = New System.Drawing.Point(428, 44)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(342, 273)
        Me.GroupBox1.TabIndex = 0
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Output"
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(147, 97)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(59, 25)
        Me.Label1.TabIndex = 7
        Me.Label1.Text = "Result"
        '
        'resultText
        '
        Me.resultText.Location = New System.Drawing.Point(101, 137)
        Me.resultText.Name = "resultText"
        Me.resultText.Size = New System.Drawing.Size(150, 31)
        Me.resultText.TabIndex = 6
        Me.resultText.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.Label3)
        Me.GroupBox2.Controls.Add(Me.Label2)
        Me.GroupBox2.Controls.Add(Me.numberText1)
        Me.GroupBox2.Controls.Add(Me.numberText2)
        Me.GroupBox2.Location = New System.Drawing.Point(29, 44)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(350, 273)
        Me.GroupBox2.TabIndex = 1
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "User Inputs"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(114, 55)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(94, 25)
        Me.Label3.TabIndex = 7
        Me.Label3.Text = "Number A"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(116, 166)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(92, 25)
        Me.Label2.TabIndex = 6
        Me.Label2.Text = "Number B"
        '
        'numberText1
        '
        Me.numberText1.Location = New System.Drawing.Point(62, 91)
        Me.numberText1.Name = "numberText1"
        Me.numberText1.PlaceholderText = "Enter First Number"
        Me.numberText1.Size = New System.Drawing.Size(190, 31)
        Me.numberText1.TabIndex = 5
        Me.numberText1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'numberText2
        '
        Me.numberText2.Location = New System.Drawing.Point(62, 203)
        Me.numberText2.Name = "numberText2"
        Me.numberText2.PlaceholderText = "Enter Second Number"
        Me.numberText2.Size = New System.Drawing.Size(190, 31)
        Me.numberText2.TabIndex = 4
        Me.numberText2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'addBtn
        '
        Me.addBtn.Location = New System.Drawing.Point(195, 389)
        Me.addBtn.Name = "addBtn"
        Me.addBtn.Size = New System.Drawing.Size(133, 34)
        Me.addBtn.TabIndex = 2
        Me.addBtn.Text = "SUM"
        Me.addBtn.UseVisualStyleBackColor = True
        '
        'subBtn
        '
        Me.subBtn.Location = New System.Drawing.Point(334, 389)
        Me.subBtn.Name = "subBtn"
        Me.subBtn.Size = New System.Drawing.Size(131, 34)
        Me.subBtn.TabIndex = 3
        Me.subBtn.Text = "DIFFERENCE"
        Me.subBtn.UseVisualStyleBackColor = True
        '
        'clearBtn
        '
        Me.clearBtn.Location = New System.Drawing.Point(471, 389)
        Me.clearBtn.Name = "clearBtn"
        Me.clearBtn.Size = New System.Drawing.Size(132, 34)
        Me.clearBtn.TabIndex = 4
        Me.clearBtn.Text = "CLEAR"
        Me.clearBtn.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(10.0!, 25.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(800, 450)
        Me.Controls.Add(Me.clearBtn)
        Me.Controls.Add(Me.subBtn)
        Me.Controls.Add(Me.addBtn)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.GroupBox1)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox1.PerformLayout()
        Me.GroupBox2.ResumeLayout(False)
        Me.GroupBox2.PerformLayout()
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents GroupBox1 As GroupBox
    Friend WithEvents GroupBox2 As GroupBox
    Friend WithEvents addBtn As Button
    Friend WithEvents subBtn As Button
    Friend WithEvents numberText2 As TextBox
    Friend WithEvents numberText1 As TextBox
    Friend WithEvents resultText As TextBox
    Friend WithEvents Label1 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents clearBtn As Button
    Friend WithEvents Timer1 As Timer
End Class
