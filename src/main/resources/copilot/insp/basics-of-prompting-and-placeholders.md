The Basics of Prompting + Placeholders + Temperature Control + Chat history + In context learning

In-context Learning vs. Chat History
The first usable version of every Language Model is often a jack of all trades. It can perform a variety of tasks at an average-ish level. If you want to specialize your model (and consequently improve its output), you have two options. You could either retrain it using new specific data or use in-context learning. AI people usually use a combination of both.
In-context learning is a prompting technique that allows you to steer the responses of your LLMs in a specific direction. All you need are a few examples, just like few-shot prompting.
The reason AI experts love in-context learning is efficiency. Instead of using a ton of high-quality data to adapt a raw model, you can use a very limited number of well-formatted examples.
Here’s a summary of In-Context Learning published by Princeton University.
In-context learning was popularized in the original GPT-3 paper as a way to use language models to learn tasks given only a few examples.[1](http://ai.stanford.edu/blog/understanding-incontext/#f1)
During in-context learning, we give the LLM a prompt that consists of a list of input-output pairs that demonstrate a task. At the end of the prompt, we append a test input and allow the LLM to make a prediction just by conditioning on the prompt and predicting the next tokens.
To correctly answer the two prompts below, the model needs to read the training examples to figure out the input distribution (financial or general news), output distribution (Positive/Negative or topic), input-output mapping (sentiment or topic classification), and the formatting.
Example#1
Circulation revenue has increased by 5% in Finland. // Positive
Panostaja did not disclose the purchase price. // Neutral
Paying off the national debt will be extremely painful. // Negative
The company anticipated its operating profit to improve. // ________
Example#2

Circulation revenue has increased by 5% in Finland. // Finance
They defeated ... in the NFC Championship Game. // Sports
Apple ... development of in-house chips. // Tech
The company anticipated its operating profit to improve. // ________

(The example of of In-Context Learning are taken from https://ai.stanford.edu/blog/understanding-incontext/)
You can derive numerous applications from in-context learning — such as generating code, automated spreadsheets, and numerous other text-oriented tasks.
ChatGPT, however, is another story. OpenAI sacrificed ChatGPT’s ability to use in-context learning to introduce a new feature: Chat history. Sure, you lose the flexibility of the model, but you get a user-friendly interface that allows for lengthy conversations.
You could argue chat history is a variant of in-context learning because ChatGPT’s responses evolve depending on the content of the chat history tab you’re using. For instance, if you feed a list of recipes into a ChatGPT tab, it’ll be able to perform specific tasks on your input. This involves summary, continuation, and editing.
Why is this important?
Depending on your needs and future discoveries, you may need to pick one of two options:
    1. Use in-context learning to fine-tune a “raw” model like GPT-4, OpenLLaMa, or Falcon. In other words, you can create a customized chatbot but the process can be tedious.
    2. Use chat history to leverage “memory” and “long conversations.” It’s easier to customize your output but the quality may go down over time.


The Basics of Prompting
Each prompt is a bridge between what you want and what your Language Model generates. The shape of your bridge depends on the problem you want to solve, but the underlying structure remains the same.
Picture this structure as six pillars:
    1. Be specific.
    2. Use placeholders <like_this> to build flexible templates. (More on this in a dedicated section).
    3. Prioritize what to do over what not to do.
    4. Specify the desired format of the output. (More on this in a dedicated section).
    5. Use double hashtags like this ## to separate different parts of your prompt. A prompt can include instructions, examples, and the desired format.
    6. Revise your prompt to remove the fluff.
Here’s an example:
[The Basics of Prompting] 

Bad prompt: Summarize this text please. [Paste text here].

***

Better prompt: I will give you a report titled <title_of_the_report> as input. Please access the report through the following link <URL_of_the_report> using the online browsing feature. Summarize the report in less than <summary_wordcount> and add <number_of_quotes> from the authors. Make sure to pick precise quotes and list them as bullet points.

<title_of_the_report> = Walking for good health.
<URL_of_the_report> = https://www.betterhealth.vic.gov.au/health/healthyliving/walking-for-good-health
<summary_wordcount> = 250
<number_of_quotes> = 3

##

Desired format:

Title: <title_of_the_report> 
Link: <URL_of_the_report>

Summary of the report based on the previous instructions.

- Quote #1
- Quote #2
- Quote #3
- etc.


Use <placeholders>
Placeholders <like_this> help you achieve two separate goals.
    1. Use <placeholders> to write flexible prompts that can take different inputs. You have to indicate the content of each placeholder in your prompt. In this case, a placeholder is a parameter.
    2. Use empty <placeholders> to illustrate the desired format. Here you don’t have to write the content of each placeholder. Your LLM will guess what each placeholder stands for, especially when you use known frameworks like User Stories or cover letters. In this case, a placeholder is an instruction.
🟢 How to use placeholders as parameters
[Use placeholders as parameters]



Context: Use <placeholders> to write flexible prompts.



Prompt example #1:



Act like an expert developer in <name_of_the_input_programming_language> and <name_of_the_output_programming_language>. I will submit a few lines of <name_of_the_input_programming_language> in the chat, and you'll rewrite it in the <name_of_the_output_programming_language>.

Make sure to use a temperature of <temperature_value>.



##



<name_of_the_input_programming_language> = Python.

<name_of_the_output_programming_language> = JavaScript.

<temperature_value> = 0.



***



Prompt example #2:



Act like an expert developer in <name_of_the_input_programming_language> and <name_of_the_output_programming_language>. I will submit a few lines of <name_of_the_input_programming_language> in the chat, and you'll rewrite it in the <name_of_the_output_programming_language>.

Make sure to use a temperature of <temperature_value>.



##



<name_of_the_input_programming_language> = PHP.

<name_of_the_output_programming_language> = Python.

<temperature_value> = 0.3.
🟢 How to use placeholders as instructions
[Use placeholders as instructions]



Context: User Story generation for a Product Owner.



Prompt:



You'll act as a Product Owner for an app that provides international shipment services for factories and retailers. I will give you a description of several features, and you'll kindly format them in the User Story format indicated below.



- Modify an order within the 12 hours (fixed) that follow the submission.

- Lockscreen notifications for every step of the shipment.

- Summary of ongoing orders ranked by date, cost, country, and products.

- A history log of past orders ranked by date, cost, country, and products.

- Chatbot incon that opens a chat window inside the web page.

- "Call me" button.



##



Desired format:



/////// User Story #1: <name_of_user_story> ///////



As a <description_of_user>,

I want <functionality>,

So that <benefit>.



Acceptance criteria:



#1 Given <precondition>

When <action_taken>,

Then <expected_result>.



#2 Given <precondition>

When <action_taken>,

Then <expected_result>.



#3 Given <precondition>

When <action_taken>,

Then <expected_result>.



/////// End of User Story#1: <name_of_user_story> ///////



---



/////// User Story #2: <name_of_user_story> ///////



etc.



##



Example of the desired output: 



/////// User Story #1: Online Shopping Cart ///////



As a frequent online shopper,

I want to be able to easily add items to my shopping cart,

So that I can efficiently complete my purchases.





Acceptance criteria:



#1 Given that I am on a product page,

When I click the "Add to Cart" button,

Then the selected item should be added to my shopping cart.



#2 Given that I have multiple items in my shopping cart,

When I view my shopping cart,

Then I should see a list of all items in my cart along with their prices and quantities.



#3 Given that I want to adjust the quantity of an item in my cart,

When I update the quantity of the item and click "Update Cart",

Then the quantity of the item should be updated and the total cost should reflect the change.



#4 Given that I want to remove an item from my shopping cart,

When I click the "Remove" button next to the item,

Then the item should be removed from my cart and the total cost should be adjusted accordingly



#5 Given that I want to apply a coupon code to my order, 

When I enter the code during checkout,

Then the discount associated with the code should be applied to my order. notes.



/////// End of User Story#1: Online Shopping Cart ///////



---



/////// User Story #2: ..... ///////



etc.


Temperature Control
Temperature is a parameter that influences the “randomness” of the response generated by your language model. It typically ranges from 0 to 1, but in some instances, you can bring the temperature beyond 1.
    • Lower temperatures (between 0.1 and 0.3) produce the most likely response. In other words, you get the most “conservative” output. Low temperatures are particularly useful when generating code because you get the most stable output.
    • Higher temperatures (between 0.7 and 0.9) lead to more creative responses.
One way to memorize the use of temperature: “Cold for code; hot for prose.” Here’s how you can introduce it in a prompt:
[Temperature control]

Example #1: At a temperature of 0.7, please explain why banana bread is called "bread" and not "cake" even though it tastes like a cake.

***

Example #2: Write a Python script that transposes a 10x10 matrix. Please provide two versions of the code where the first is generated at a temperature of 0 and the second at a temperature of 0.4.

***

Example #3: Act like an expert developer in <name_of_the_programming_language>. I will submit a few lines of code in the chat, and you'll review the code, then perform the following 7 tasks in the specified order defined below. When you write code, always use a temperature of <temperature_value>.

1. Look for errors and explain them.
2. Correct the errors.
3. Optimize the code.
4. Add comments to explain the purpose of each line.
5. Format the code to make it easier to read.
6. Make sure to reason step by step to be sure you arrive at the right answers.
7. Comment on every single step you make.

##

<name_of_the_programming_language> = Python.
<temperature_value> = 0.
