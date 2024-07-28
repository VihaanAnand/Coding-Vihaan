try:
        from email import encoders
        from email.mime.base import MIMEBase
        from email.mime.multipart import MIMEMultipart
        from email.mime.text import MIMEText
        import smtplib
        myemail = "myemail@domain.com"
        password = "password"
        recipients = ["recipient1@domain.com", "recipient2@domain.com"]
        subject = "Test email sent with Python smtplib"
        body = "Hello! I sent this email with the smtplib Python library. In order to fill up the space, I'm going to paste filler text. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Nunc mattis enim ut tellus elementum. Commando elite at imperdiet dui accumsan sit amet nulla facilisi. Purus semper eget duis at tellus at urna condimentum mattis. Sit amet nisl suscipit adipiscing bibendum est ultricies integer. Non nisi est sit amet facilisis magna etiam tempor. Metus."
        attachment = "profile.png"
        message = MIMEMultipart()
        message["From"] = myemail
        message["To"] = ", ".join(recipients)
        message["Subject"] = subject
        message.attach(MIMEText(body, "plain"))
        with open(attachment, "rb") as file:
                part = MIMEBase("application", "octet-stream")
                part.set_payload(file.read())
        encoders.encode_base64(part)
        part.add_header("Content-Disposition", f"attachment; filename = {attachment}")
        message.attach(part)
        server = smtplib.SMTP("smtp-mail.outlook.com", 587)
        server.starttls()
        server.login(myemail, password)
        server.send_message(message)
        server.quit()
except Exception as error:
        print(f"Error - {error}")