To parse the einsteintoolkit code and upload to huggingface, do the following in the root dir of the repo:

```bash
python data_parser/ETdata_hf_code.py
python data_parser/ETdata_hf_test.py
python data_parser/ET_code_ds_add_context.py
python data_parser/ET_code_ds_add_docs.py
```
