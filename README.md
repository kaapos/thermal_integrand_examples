# Integrand Evaluation Examples

Examples demonstrating the evaluation of loop integrands at finite temperature and chemical potential

## Dependencies

This project requires the **factorint branch** of Symbolica:

```bash
pip install git+https://github.com/benruijl/symbolica.git@factorint
```

## Installation

1. Install the factorint branch of Symbolica (see above)
2. Install other dependencies:
   ```bash
   pip install -r requirements.txt
   ```

## Usage

Run the example:
```bash
python example_symbolica_integrand.py
```

## Project Structure

- `examples/` - Configuration files and integrand definitions
- `integrand.py` - Abstract class for integrands
- `symbolica_integrand.py` - Symbolica implementation of integrands
