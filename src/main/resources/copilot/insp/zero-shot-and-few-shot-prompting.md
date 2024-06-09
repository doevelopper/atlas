Zero-Shot Prompting (no examples)
Zero-shot prompting is to write an instruction for your AI model without providing context or examples. The basic format of zero-shot involves two parts often called “Text” and “Desired Result.”
Here are two examples of zero-shot prompts:
[Zero-shot prompting]





Prompt example #1:



Question: Two years ago, Jotaro was three times as old as his brother was. In three years’ time, Jotaro will be twice as old as his brother. How old is Jotaro?

Answer:



***



Prompt example #2:



Text: My favorite part of networking events is to stand next to the buffet table and watch people struggle to impress each other.

Tone:
This particular format of zero-shot prompting is rare outside of AI labs where experts use the technique to test the capabilities of their models.
The most common format of zero-shot prompting is the one you use naturally. You just type your question. You don’t need the “Text + Desired output” format. That’s because user-friendly models like ChatGPT and Bard are optimized for dialogue — and every dialogue is a series of zero-shots.
You could say chatbots are zero-shot machines.


Few-Shot Prompting (several high-quality examples)
Few-shot prompting is also known as in-context learning. You give your Language Model a bunch of high-quality examples to improve its “guesses.” The number of examples depends on your model, but you can start with three to five inputs.
Here’s an example:
[Few-shot prompting]

Prompt:

Text #1: My favorite part of networking events is eating all the food while everybody is busy trying to impress each other. 

Tone #1: Playful.

##

Text #2: She stormed out of the conference room, slamming the door behind 42 staff members who instantly turned their eyes away as if ashamed of their lack of courage.

Tone #2: Angry.

##

Text #3: Do you think they noticed the missing "export" feature in today's demo? I'm pretty sure Nabil whispered something into the client's ear. I really don't like that bald dude!
Tone #3: Anxious.

##

Text #4: Wait, what the hell is a dish washer? And why aren't there any horses attached to your chariot?

Tone #4:
It’s not necessary to add a number to each example (like #1, #2, #3), but doing so can improve the output. Another element you want to add to your examples is “noise.”
Noise is information that’s not useful for the task given to your Language Model. In the “Tone” examples, I introduced misleading sentences to confuse the system and force it to focus on the “signal.”
If you make the task too obvious for your Language Model, it may underperform when faced with complex examples.


Zero-Shot/Few-Shot — The simple version
If you want to remember something from zero-shot and few-shot, remember the following:
    • When your Language Model fails to give you the desired response, add high-quality examples to your prompt.
Here’s an illustration of how few-shot can help you improve ChatGPT’s output.
[Zero-shot/Few-shot - The simple version]

Attempt #1 (Zero-shot)

Text: My favorite part of networking events is to stand next to the buffet table and watch people struggle to impress each other.

Tone:


* ChatGPT's output: "The tone of this text is casual and light-hearted. The speaker seems to be expressing a personal preference for the food at network events, and is making an observation about the behavior of the attendees in a somewhat playful manner."

(The output doesn't match my expectation because I wanted a one-word answer)


***


Attempt #2 (Few-shot)

Text: She stormed out of the conference room, slamming the door behind all 42 attendees, many of whom instantly turned their eyes away as if ashamed of their lack of courage.

Tone: Angry.

##

Text: Do you think they noticed the missing "export" feature in today's demo? I'm pretty sure Nabil whispered something into the client's ear. I really don't like that bald dude!

Tone: Anxious.

##

Text: My favorite part of network events is to stand next to the buffet table and watch people struggle to impress each other.

Tone:


* ChatGPT's output: "Amused."
