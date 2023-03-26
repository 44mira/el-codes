
const message = document.getElementById("input_message");
const send_btn = document.getElementById("send_message");
const clear_btn = document.getElementById("clear_message");
const output = document.getElementById("text_output"); 

// clears output
output.textContent = "";

send_btn.onclick = () => {
    const sent_message = message.value;

    // catch empty send 
    if (sent_message == "")
        return;
    
    // clear buffer
    message.value = "";
    console.log(output.value);
    
    // catch first message appending to nothing
    let current_text;
    if (output.textContent != "")
        current_text = output.textContent;
    else
        current_text = "";

    // appends message and new lines
    output.textContent = current_text + "User: " + sent_message + "\n";
};

clear_btn.onclick = () => {
    message.value = "";
};

document.addEventListener("keydown", (event) => {
    // when Enter is pressed
    if (event.code === 'Enter'){
        send_btn.onclick()
    }
});

